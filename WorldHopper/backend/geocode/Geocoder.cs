using System.Globalization;
using System.Text.Json;

namespace geocode;

public sealed record Coordinate(double Lat, double Lon, string DisplayName);

// Resolves place names to coordinates via OpenStreetMap Nominatim, caching results in a
// git-ignored JSON file and honouring the usage policy (one request/second, descriptive User-Agent).
public sealed class Geocoder : IDisposable
{
    private const string Endpoint = "https://nominatim.openstreetmap.org/search";
    private const string UserAgent = "WorldHopper/1.0 (geocoding preprocessor)";
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

        var url = $"{Endpoint}?q={Uri.EscapeDataString(place)}&format=json&limit=1";
        using var response = await _http.GetAsync(url);
        response.EnsureSuccessStatusCode();

        await using var stream = await response.Content.ReadAsStreamAsync();
        using var document = await JsonDocument.ParseAsync(stream);
        if (document.RootElement.ValueKind != JsonValueKind.Array || document.RootElement.GetArrayLength() == 0)
        {
            return null;
        }

        var match = document.RootElement[0];
        var lat = double.Parse(match.GetProperty("lat").GetString()!, CultureInfo.InvariantCulture);
        var lon = double.Parse(match.GetProperty("lon").GetString()!, CultureInfo.InvariantCulture);
        var displayName = match.TryGetProperty("display_name", out var dn) ? dn.GetString() ?? place : place;

        var coordinate = new Coordinate(lat, lon, displayName);
        _cache[key] = coordinate;
        SaveCache();
        return coordinate;
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
