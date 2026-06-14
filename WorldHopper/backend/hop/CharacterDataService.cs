using System.Globalization;

namespace hop;

// Loads per-character itineraries from the CSV files in the configured data folder.
// Each file is one character (name = file name without extension); rows are `date,lat,lon,kind,via`.
public sealed class CharacterDataService
{
    private readonly string? _dataPath;
    private readonly ILogger<CharacterDataService> _logger;

    public CharacterDataService(IConfiguration configuration, ILogger<CharacterDataService> logger)
    {
        _dataPath = configuration["WorldHopper:DataPath"];
        _logger = logger;
    }

    public IReadOnlyList<Character> GetCharacters()
    {
        if (string.IsNullOrWhiteSpace(_dataPath) || !Directory.Exists(_dataPath))
        {
            _logger.LogWarning("WorldHopper:DataPath '{DataPath}' is not set or does not exist; serving no characters.", _dataPath);
            return [];
        }

        var characters = new List<Character>();
        foreach (var path in Directory.EnumerateFiles(_dataPath, "*.csv").OrderBy(p => p, StringComparer.Ordinal))
        {
            var hops = ReadHops(path);
            if (hops.Count > 0)
            {
                characters.Add(new Character(Path.GetFileNameWithoutExtension(path), hops));
            }
        }

        return characters;
    }

    private List<Hop> ReadHops(string path)
    {
        var hops = new List<Hop>();
        var lineNumber = 0;

        foreach (var raw in File.ReadLines(path))
        {
            lineNumber++;
            var line = raw.Trim();
            if (line.Length == 0)
            {
                continue;
            }

            var fields = line.Split(',');
            if (!DateOnly.TryParse(fields[0], CultureInfo.InvariantCulture, DateTimeStyles.None, out var date))
            {
                // The first non-empty line may be the `date,lat,lon,kind` header; anything else is an error.
                if (lineNumber > 1)
                {
                    _logger.LogWarning("{File} line {Line}: '{Value}' is not a date; row skipped.", path, lineNumber, fields[0]);
                }
                continue;
            }

            if (fields.Length < 4
                || !double.TryParse(fields[1], NumberStyles.Float, CultureInfo.InvariantCulture, out var lat)
                || !double.TryParse(fields[2], NumberStyles.Float, CultureInfo.InvariantCulture, out var lon)
                || !TryParseKind(fields[3], out var kind))
            {
                _logger.LogWarning("{File} line {Line}: malformed row '{Row}'; skipped.", path, lineNumber, line);
                continue;
            }

            var via = fields.Length >= 5 ? ParseVia(fields[4]) : [];
            hops.Add(new Hop(date, lat, lon, kind, via));
        }

        hops.Sort((a, b) => a.Date.CompareTo(b.Date));
        return hops;
    }

    // The optional 5th CSV field is a tour tail: `lat lon;lat lon;...` (space between a pair's
    // coordinates, semicolon between pairs). Empty or absent means a single-leg hop.
    private static IReadOnlyList<Waypoint> ParseVia(string field)
    {
        var pairs = field.Split(';', StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries);
        var waypoints = new List<Waypoint>(pairs.Length);
        foreach (var pair in pairs)
        {
            var parts = pair.Split(' ', StringSplitOptions.RemoveEmptyEntries);
            if (parts.Length == 2
                && double.TryParse(parts[0], NumberStyles.Float, CultureInfo.InvariantCulture, out var lat)
                && double.TryParse(parts[1], NumberStyles.Float, CultureInfo.InvariantCulture, out var lon))
            {
                waypoints.Add(new Waypoint(lat, lon));
            }
        }

        return waypoints;
    }

    private static bool TryParseKind(string value, out HopKind kind)
    {
        switch (value.Trim().ToLowerInvariant())
        {
            case "long":
                kind = HopKind.Long;
                return true;
            case "short":
                kind = HopKind.Short;
                return true;
            default:
                kind = default;
                return false;
        }
    }
}
