using System.Globalization;
using System.Text;
using geocode;

// Turns each `<name>.places` raw itinerary in the data folder into a `<name>.csv` of dated
// coordinates, geocoding place names via Nominatim. Place/date/coordinate data is never committed.
var dataPath = ResolveDataPath(args, out var only);
if (dataPath is null)
{
    Console.Error.WriteLine("No data path. Pass --data <path> or set WorldHopper__DataPath.");
    return 2;
}

if (!Directory.Exists(dataPath))
{
    Console.Error.WriteLine($"Data path '{dataPath}' does not exist.");
    return 2;
}

var rawFiles = Directory.EnumerateFiles(dataPath, "*.places")
    .Where(f => only.Count == 0 || only.Contains(Path.GetFileNameWithoutExtension(f)))
    .OrderBy(f => f, StringComparer.Ordinal)
    .ToList();

if (rawFiles.Count == 0)
{
    Console.Error.WriteLine($"No .places files found in '{dataPath}'.");
    return 1;
}

using var geocoder = new Geocoder(Path.Combine(dataPath, ".geocode-cache.json"));
var hadErrors = false;

foreach (var file in rawFiles)
{
    var name = Path.GetFileNameWithoutExtension(file);
    Console.WriteLine($"== {name} ==");

    var itinerary = ItineraryParser.Parse(file);
    ItineraryValidator.Validate(itinerary);

    foreach (var warning in itinerary.Warnings)
    {
        Console.WriteLine($"  warning: {warning}");
    }

    if (itinerary.Errors.Count > 0)
    {
        foreach (var error in itinerary.Errors)
        {
            Console.Error.WriteLine($"  error: {error}");
        }

        Console.Error.WriteLine($"  {name}: {itinerary.Errors.Count} error(s); CSV not written.");
        hadErrors = true;
        continue;
    }

    if (itinerary.Lives.Count == 0)
    {
        Console.Error.WriteLine($"  {name}: no 'live' entries; CSV not written.");
        hadErrors = true;
        continue;
    }

    // A live is the long hop on its start date; each connected travel run is one short blue tour.
    var rows = itinerary.ToHopRows();

    var resolved = new Dictionary<string, Coordinate>(StringComparer.OrdinalIgnoreCase);
    var unresolved = false;
    foreach (var place in rows.SelectMany(r => r.AllPlaces).Distinct(StringComparer.OrdinalIgnoreCase))
    {
        var coordinate = await geocoder.ResolveAsync(place);
        if (coordinate is null)
        {
            Console.Error.WriteLine($"  error: could not geocode '{place}'.");
            unresolved = true;
            continue;
        }

        resolved[place] = coordinate;
        Console.WriteLine($"  {place} -> {coordinate.Lat:0.####}, {coordinate.Lon:0.####}  ({coordinate.DisplayName})");
    }

    if (unresolved)
    {
        Console.Error.WriteLine($"  {name}: unresolved places; CSV not written.");
        hadErrors = true;
        continue;
    }

    var csvPath = Path.Combine(dataPath, name + ".csv");
    WriteCsv(csvPath, rows, resolved);
    Console.WriteLine($"  wrote {csvPath} ({rows.Count} rows).");
}

return hadErrors ? 1 : 0;

static string? ResolveDataPath(string[] args, out HashSet<string> only)
{
    only = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
    var dataPath = Environment.GetEnvironmentVariable("WorldHopper__DataPath");

    for (var i = 0; i < args.Length; i++)
    {
        if (args[i] is "--data" or "-d")
        {
            if (i + 1 < args.Length)
            {
                dataPath = args[++i];
            }
        }
        else
        {
            only.Add(args[i]);
        }
    }

    return string.IsNullOrWhiteSpace(dataPath) ? null : dataPath;
}

// CSV columns: date,lat,lon,kind,via. lat/lon are the hop's first place; `via` is an optional
// tour tail — the remaining places as `lat lon;lat lon;...` (space-separated pair, semicolon
// between pairs). Single-place hops leave `via` empty, so older single-leg CSVs stay valid.
static void WriteCsv(string path, IReadOnlyList<HopRow> rows, Dictionary<string, Coordinate> resolved)
{
    var builder = new StringBuilder("date,lat,lon,kind,via\n");
    foreach (var row in rows)
    {
        var c = resolved[row.Place];
        builder.Append(row.Date.ToString("yyyy-MM-dd", CultureInfo.InvariantCulture)).Append(',')
            .Append(Format(c.Lat)).Append(',')
            .Append(Format(c.Lon)).Append(',')
            .Append(row.Kind).Append(',');

        if (row.Extra is not null)
        {
            var via = row.Extra.Select(p => $"{Format(resolved[p].Lat)} {Format(resolved[p].Lon)}");
            builder.Append(string.Join(';', via));
        }

        builder.Append('\n');
    }

    File.WriteAllText(path, builder.ToString());
}

static string Format(double value) => Math.Round(value, 4).ToString(CultureInfo.InvariantCulture);
