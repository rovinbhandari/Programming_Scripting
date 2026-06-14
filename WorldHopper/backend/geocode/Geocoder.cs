using System.Globalization;
using System.Text.Json;

namespace geocode;

public sealed record Coordinate(double Lat, double Lon, string DisplayName);

// One candidate from a Nominatim search response, with the fields we rank on.
public sealed record NominatimResult(double Lat, double Lon, string DisplayName, string Category, string Type, double Importance);

// Resolves place names to coordinates via OpenStreetMap Nominatim, caching results in a
// git-ignored JSON file and honouring the usage policy (one request/second, descriptive User-Agent).
public sealed class Geocoder : IDisposable
{
    private const string Endpoint = "https://nominatim.openstreetmap.org/search";
    private const string UserAgent = "WorldHopper/1.0 (geocoding preprocessor)";
    private const int CandidateLimit = 10; // ask for several matches so we can pass over offshore polygons for a land node
    private static readonly TimeSpan MinInterval = TimeSpan.FromMilliseconds(1100);
    private static readonly JsonSerializerOptions CacheJson = new() { WriteIndented = true, PropertyNameCaseInsensitive = true };

    private readonly HttpClient _http = new();
    private readonly string _cachePath;
    private readonly Dictionary<string, Coordinate> _cache;
    private DateTime _lastRequest = DateTime.MinValue;

    public Geocoder(string cachePath)
    {
        _cachePath = cachePath;
        _cache = LoadCache(cachePath);
        _http.DefaultRequestHeaders.UserAgent.ParseAdd(UserAgent);
    }

    // Returns the coordinate for a place, or null when Nominatim finds no match.
    public async Task<Coordinate?> ResolveAsync(string place)
    {
        var key = place.Trim().ToLowerInvariant();
        if (_cache.TryGetValue(key, out var cached))
        {
            return cached;
        }

        await ThrottleAsync();

        var url = $"{Endpoint}?q={Uri.EscapeDataString(place)}&format=json&limit={CandidateLimit}";
        using var response = await _http.GetAsync(url);
        response.EnsureSuccessStatusCode();

        await using var stream = await response.Content.ReadAsStreamAsync();
        using var document = await JsonDocument.ParseAsync(stream);
        var best = SelectBest(ParseResults(document.RootElement));
        if (best is null)
        {
            return null;
        }

        var displayName = string.IsNullOrEmpty(best.DisplayName) ? place : best.DisplayName;
        var coordinate = new Coordinate(best.Lat, best.Lon, displayName);
        _cache[key] = coordinate;
        SaveCache();
        return coordinate;
    }

    // Parse a Nominatim `format=json` response array into candidates, skipping malformed entries.
    public static IReadOnlyList<NominatimResult> ParseResults(JsonElement root)
    {
        var results = new List<NominatimResult>();
        if (root.ValueKind != JsonValueKind.Array)
        {
            return results;
        }

        foreach (var element in root.EnumerateArray())
        {
            if (TryParseResult(element, out var result))
            {
                results.Add(result);
            }
        }

        return results;
    }

    private static bool TryParseResult(JsonElement element, out NominatimResult result)
    {
        result = null!;
        if (!element.TryGetProperty("lat", out var latEl) || latEl.ValueKind != JsonValueKind.String ||
            !element.TryGetProperty("lon", out var lonEl) || lonEl.ValueKind != JsonValueKind.String ||
            !double.TryParse(latEl.GetString(), NumberStyles.Float, CultureInfo.InvariantCulture, out var lat) ||
            !double.TryParse(lonEl.GetString(), NumberStyles.Float, CultureInfo.InvariantCulture, out var lon))
        {
            return false;
        }

        var displayName = element.TryGetProperty("display_name", out var dn) ? dn.GetString() ?? "" : "";
        var category = element.TryGetProperty("class", out var cl) ? cl.GetString() ?? "" : "";
        var type = element.TryGetProperty("type", out var ty) ? ty.GetString() ?? "" : "";
        var importance = element.TryGetProperty("importance", out var im) && im.ValueKind == JsonValueKind.Number
            ? im.GetDouble()
            : 0.0;
        result = new NominatimResult(lat, lon, displayName, category, type, importance);
        return true;
    }

    // Pick the candidate most likely to sit on the place itself. Nominatim ranks by `importance`,
    // but its top hit for a coastal or ambiguous name can be a region/water polygon whose
    // representative point falls offshore; a populated-place node sits at the settlement centre.
    // So rank by feature kind first (Score), then fall back to Nominatim's importance order.
    public static NominatimResult? SelectBest(IReadOnlyList<NominatimResult> candidates)
    {
        NominatimResult? best = null;
        var bestScore = int.MinValue;
        var bestImportance = double.NegativeInfinity;
        foreach (var candidate in candidates)
        {
            var score = Score(candidate.Category, candidate.Type);
            if (score > bestScore || (score == bestScore && candidate.Importance > bestImportance))
            {
                best = candidate;
                bestScore = score;
                bestImportance = candidate.Importance;
            }
        }

        return best;
    }

    // Rank a Nominatim feature by how reliably its point lands where a traveller actually goes:
    // settlement nodes on land score highest; water/natural features (offshore-prone) score lowest.
    public static int Score(string category, string type)
    {
        if (category is "natural" or "waterway" or "water"
            || type is "sea" or "ocean" or "bay" or "strait" or "water" or "beach" or "cape" or "reef")
        {
            return -1;
        }

        if (category == "place")
        {
            return type switch
            {
                "city" or "town" or "village" or "hamlet" or "municipality"
                    or "suburb" or "neighbourhood" or "quarter"
                    or "locality" or "isolated_dwelling" => 3,
                _ => 2,
            };
        }

        if (category == "boundary" && type == "administrative")
        {
            return 1;
        }

        return 0;
    }

    private async Task ThrottleAsync()
    {
        var elapsed = DateTime.UtcNow - _lastRequest;
        if (elapsed < MinInterval)
        {
            await Task.Delay(MinInterval - elapsed);
        }
        _lastRequest = DateTime.UtcNow;
    }

    private static Dictionary<string, Coordinate> LoadCache(string path)
    {
        if (!File.Exists(path))
        {
            return new Dictionary<string, Coordinate>();
        }

        try
        {
            return JsonSerializer.Deserialize<Dictionary<string, Coordinate>>(File.ReadAllText(path), CacheJson)
                   ?? new Dictionary<string, Coordinate>();
        }
        catch (JsonException)
        {
            return new Dictionary<string, Coordinate>();
        }
    }

    private void SaveCache() => File.WriteAllText(_cachePath, JsonSerializer.Serialize(_cache, CacheJson));

    public void Dispose() => _http.Dispose();
}
