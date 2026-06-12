using System.Globalization;

namespace geocode;

// A temporary trip away from the current home: a blue (short) hop on its start date.
public sealed record Travel(string Place, DateOnly Start, DateOnly End, int Line);

// A long-term home: a red (long) hop on its start date, with any short trips nested under it.
public sealed class Live(string place, DateOnly start, DateOnly end, int line)
{
    public string Place { get; } = place;
    public DateOnly Start { get; } = start;
    public DateOnly End { get; } = end;
    public int Line { get; } = line;
    public List<Travel> Travels { get; } = [];
}

// One output row: a dated hop of a given kind ("long" or "short").
public sealed record HopRow(DateOnly Date, string Place, string Kind);

// A single character's parsed itinerary plus any problems found while reading and validating it.
public sealed class Itinerary
{
    public List<Live> Lives { get; } = [];
    public List<string> Errors { get; } = [];
    public List<string> Warnings { get; } = [];

    // The CSV view: each live is a long hop on its start date; each travel a short hop on its start date.
    public IReadOnlyList<HopRow> ToHopRows()
    {
        var rows = new List<HopRow>();
        foreach (var live in Lives)
        {
            rows.Add(new HopRow(live.Start, live.Place, "long"));
            rows.AddRange(live.Travels.Select(t => new HopRow(t.Start, t.Place, "short")));
        }

        rows.Sort((a, b) => a.Date.CompareTo(b.Date));
        return rows;
    }
}

// Reads the human-friendly `.places` format:
//   # comments and blank lines are ignored
//   live, <place>, <start> .. <end>
//       travel, <place>, <start> .. <end>   (belongs to the live above; indentation is cosmetic)
// Place names may contain commas (e.g. "Oslo, Norway"); the range is always the last comma field.
public static class ItineraryParser
{
    public static Itinerary Parse(string file) => Parse(File.ReadLines(file));

    public static Itinerary Parse(IEnumerable<string> lines)
    {
        var itinerary = new Itinerary();
        Live? current = null;
        var lineNumber = 0;

        foreach (var rawLine in lines)
        {
            lineNumber++;
            var line = rawLine.Trim();
            if (line.Length == 0 || line.StartsWith('#'))
            {
                continue;
            }

            var parts = line.Split(',');
            var keyword = parts[0].Trim().ToLowerInvariant();
            if (keyword is not ("live" or "travel"))
            {
                itinerary.Errors.Add($"line {lineNumber}: expected a line starting with 'live' or 'travel', got '{parts[0].Trim()}'.");
                continue;
            }

            if (parts.Length < 3)
            {
                itinerary.Errors.Add($"line {lineNumber}: expected '{keyword}, <place>, <start> .. <end>'.");
                continue;
            }

            var place = string.Join(", ", parts[1..^1].Select(p => p.Trim()));
            if (place.Length == 0)
            {
                itinerary.Errors.Add($"line {lineNumber}: the place name is empty.");
                continue;
            }

            if (!TryParseRange(parts[^1], out var start, out var end))
            {
                itinerary.Errors.Add($"line {lineNumber}: '{parts[^1].Trim()}' is not a '<start> .. <end>' date range (use YYYY-MM-DD .. YYYY-MM-DD).");
                continue;
            }

            if (start > end)
            {
                itinerary.Errors.Add($"line {lineNumber}: start {start:yyyy-MM-dd} is after end {end:yyyy-MM-dd}.");
                continue;
            }

            if (keyword == "live")
            {
                current = new Live(place, start, end, lineNumber);
                itinerary.Lives.Add(current);
            }
            else if (current is null)
            {
                itinerary.Errors.Add($"line {lineNumber}: 'travel' before any 'live'.");
            }
            else
            {
                current.Travels.Add(new Travel(place, start, end, lineNumber));
            }
        }

        return itinerary;
    }

    private static bool TryParseRange(string text, out DateOnly start, out DateOnly end)
    {
        start = default;
        end = default;
        var parts = text.Split("..", StringSplitOptions.TrimEntries | StringSplitOptions.RemoveEmptyEntries);
        return parts.Length == 2 && TryParseDate(parts[0], out start) && TryParseDate(parts[1], out end);
    }

    private static bool TryParseDate(string text, out DateOnly date) =>
        DateOnly.TryParse(text, CultureInfo.InvariantCulture, DateTimeStyles.None, out date);
}

// Option A: end dates inform validation only; the CSV still records start dates as `date,lat,lon,kind`.
public static class ItineraryValidator
{
    public static void Validate(Itinerary itinerary)
    {
        var lives = itinerary.Lives;
        for (var i = 0; i < lives.Count; i++)
        {
            var live = lives[i];

            foreach (var travel in live.Travels)
            {
                if (travel.Start < live.Start || travel.End > live.End)
                {
                    itinerary.Errors.Add(
                        $"line {travel.Line}: travel '{travel.Place}' ({travel.Start:yyyy-MM-dd}..{travel.End:yyyy-MM-dd}) falls outside its live in '{live.Place}' ({live.Start:yyyy-MM-dd}..{live.End:yyyy-MM-dd}).");
                }
            }

            if (i > 0)
            {
                var previous = lives[i - 1];
                if (previous.End != live.Start)
                {
                    var kind = previous.End < live.Start ? "gap" : "overlap";
                    itinerary.Warnings.Add(
                        $"line {live.Line}: {kind} between '{previous.Place}' (ends {previous.End:yyyy-MM-dd}) and '{live.Place}' (starts {live.Start:yyyy-MM-dd}).");
                }
            }
        }
    }
}
