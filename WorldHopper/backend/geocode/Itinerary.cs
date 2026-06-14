using System.Globalization;

namespace geocode;

// A trip away from the current base: a blue (short) hop on its start date. A travel may itself
// host nested travels — sub-trips taken from this place before returning to it.
public sealed class Travel(string place, DateOnly start, DateOnly end, int line)
{
    public string Place { get; } = place;
    public DateOnly Start { get; } = start;
    public DateOnly End { get; } = end;
    public int Line { get; } = line;
    public List<Travel> Travels { get; } = [];
}

// A home base: a red (long) hop on its start date. A top-level live is a sequential home (you
// settle and stay). A live nested under another live is a temporary relocation — you live at the
// nested place for its range, then return to the parent's place. Either can host short trips
// (Travels) and further temporary relocations (Lives).
public sealed class Live(string place, DateOnly start, DateOnly end, int line)
{
    public string Place { get; } = place;
    public DateOnly Start { get; } = start;
    public DateOnly End { get; } = end;
    public int Line { get; } = line;
    public List<Travel> Travels { get; } = [];
    public List<Live> Lives { get; } = [];
}

// One output row: a dated hop of a given kind ("long" or "short"). A short hop may be a multi-leg
// tour — Place is the first place visited and Extra holds the ordered places after it (home is
// implicit: the flyer leaves home, visits Place then each Extra in turn, and returns home).
public sealed record HopRow(DateOnly Date, string Place, string Kind, IReadOnlyList<string>? Extra = null)
{
    // Every place this row references, in visiting order (used to geocode the row).
    public IReadOnlyList<string> AllPlaces => Extra is null ? [Place] : [Place, .. Extra];
}

// A single character's parsed itinerary plus any problems found while reading and validating it.
public sealed class Itinerary
{
    public List<Live> Lives { get; } = [];
    public List<string> Errors { get; } = [];
    public List<string> Warnings { get; } = [];

    // The CSV view: a time-ordered list of long (red) and short (blue) hops.
    //   - each top-level live is a long hop on its start date (a new home you stay at);
    //   - a nested live is a temporary relocation: a long hop out on its start date, then a long
    //     hop back to the parent's place once its run ends (date-contiguous siblings chain);
    //   - each maximal run of connected travels is one short hop — a blue tour that leaves home,
    //     visits each place in turn (sub-trips branch off and return to their base), and comes home.
    public IReadOnlyList<HopRow> ToHopRows()
    {
        var rows = new List<HopRow>();
        foreach (var live in Lives)
        {
            rows.Add(new HopRow(live.Start, live.Place, "long"));
            EmitNestedLives(live.Lives, live.Place, live.End, rows);
            EmitTours(live.Travels, rows);
        }

        rows.Sort((a, b) => a.Date.CompareTo(b.Date));
        return rows;
    }

    // A nested live is a temporary relocation: a long hop out on its start date, then a long hop
    // back to the parent's place when its run ends — unless it runs right up to the parent's own
    // end (the next home takes over) or chains straight into a date-contiguous sibling.
    private static void EmitNestedLives(List<Live> lives, string parentPlace, DateOnly parentEnd, List<HopRow> rows)
    {
        for (var i = 0; i < lives.Count; i++)
        {
            var live = lives[i];
            rows.Add(new HopRow(live.Start, live.Place, "long"));
            EmitNestedLives(live.Lives, live.Place, live.End, rows);
            EmitTours(live.Travels, rows);

            var chained = i + 1 < lives.Count && lives[i + 1].Start == live.End;
            if (!chained && live.End < parentEnd)
            {
                rows.Add(new HopRow(live.End, parentPlace, "long"));
            }
        }
    }

    // Travels connect when one starts exactly as the previous ends, so each maximal date-contiguous
    // run of sibling travels becomes a single blue tour: the flyer leaves home, visits each place in
    // order, and returns home. A travel's own nested travels are sub-trips that branch from it and
    // return to it (again chaining contiguous ones), so a tour is the depth-first list of places
    // visited, with the base re-inserted whenever a sub-run ends.
    private static void EmitTours(List<Travel> travels, List<HopRow> rows)
    {
        foreach (var run in SplitContiguousRuns(travels))
        {
            var waypoints = new List<string>();
            foreach (var travel in run)
            {
                waypoints.Add(travel.Place);
                AppendSubtour(travel, waypoints);
            }

            var extra = waypoints.Count > 1 ? waypoints.GetRange(1, waypoints.Count - 1) : null;
            rows.Add(new HopRow(run[0].Start, waypoints[0], "short", extra));
        }
    }

    // Splice a travel's nested sub-trips into the tour: each contiguous sub-run branches from the
    // travel's place and returns to it before the next sub-run (or the rest of the parent tour).
    private static void AppendSubtour(Travel travel, List<string> waypoints)
    {
        foreach (var run in SplitContiguousRuns(travel.Travels))
        {
            foreach (var child in run)
            {
                waypoints.Add(child.Place);
                AppendSubtour(child, waypoints);
            }

            waypoints.Add(travel.Place); // back to base before the next sub-run / parent leg
        }
    }

    // Split sibling travels (ordered by start date) into maximal runs where each travel starts
    // exactly when the previous one ends — the runs that play as one connected blue tour.
    private static List<List<Travel>> SplitContiguousRuns(List<Travel> travels)
    {
        var runs = new List<List<Travel>>();
        foreach (var travel in travels.OrderBy(t => t.Start).ThenBy(t => t.Line))
        {
            if (runs.Count > 0 && runs[^1][^1].End == travel.Start)
            {
                runs[^1].Add(travel);
            }
            else
            {
                runs.Add([travel]);
            }
        }

        return runs;
    }
}

// Reads the human-friendly `.places` format:
//   # comments and blank lines are ignored
//   live, <place>, <start> .. <end>
//       travel, <place>, <start> .. <end>     (indented under the live → a trip from it)
//       live,   <place>, <start> .. <end>     (indented under the live → a temporary relocation)
//           travel, <place>, <start> .. <end> (indented under a travel → a nested sub-trip)
// Indentation is SIGNIFICANT: each entry nests under the nearest less-indented entry above it.
// Place names may contain commas (e.g. "Eastville, Republic of Test"); the range is always the last comma field.
public static class ItineraryParser
{
    public static Itinerary Parse(string file) => Parse(File.ReadLines(file));

    public static Itinerary Parse(IEnumerable<string> lines)
    {
        var itinerary = new Itinerary();
        var stack = new Stack<(int Indent, object Node)>(); // open ancestors; Node is a Live or a Travel
        var lineNumber = 0;

        foreach (var rawLine in lines)
        {
            lineNumber++;
            var line = rawLine.Trim();
            if (line.Length == 0 || line.StartsWith('#'))
            {
                continue;
            }

            var indent = rawLine.Length - rawLine.TrimStart().Length;
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

            // The parent is the nearest still-open entry indented less than this one.
            while (stack.Count > 0 && stack.Peek().Indent >= indent)
            {
                stack.Pop();
            }

            var parent = stack.Count > 0 ? stack.Peek().Node : null;

            if (keyword == "live")
            {
                var live = new Live(place, start, end, lineNumber);
                switch (parent)
                {
                    case null:
                        itinerary.Lives.Add(live);
                        break;
                    case Live parentLive:
                        parentLive.Lives.Add(live);
                        break;
                    default:
                        itinerary.Errors.Add($"line {lineNumber}: a 'live' cannot be nested under a 'travel'.");
                        continue;
                }

                stack.Push((indent, live));
            }
            else
            {
                var travel = new Travel(place, start, end, lineNumber);
                switch (parent)
                {
                    case Live parentLive:
                        parentLive.Travels.Add(travel);
                        break;
                    case Travel parentTravel:
                        parentTravel.Travels.Add(travel);
                        break;
                    default:
                        itinerary.Errors.Add(itinerary.Lives.Count == 0
                            ? $"line {lineNumber}: 'travel' before any 'live'."
                            : $"line {lineNumber}: 'travel' must be indented under a 'live' or another 'travel'.");
                        continue;
                }

                stack.Push((indent, travel));
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
// Every nested entry must fall within its parent's date range; consecutive top-level lives that
// don't meet end-to-start are flagged as a gap or overlap (a warning, not an error).
public static class ItineraryValidator
{
    public static void Validate(Itinerary itinerary)
    {
        var lives = itinerary.Lives;
        for (var i = 0; i < lives.Count; i++)
        {
            ValidateLive(lives[i], itinerary);

            if (i > 0)
            {
                var previous = lives[i - 1];
                var live = lives[i];
                if (previous.End != live.Start)
                {
                    var kind = previous.End < live.Start ? "gap" : "overlap";
                    itinerary.Warnings.Add(
                        $"line {live.Line}: {kind} between '{previous.Place}' (ends {previous.End:yyyy-MM-dd}) and '{live.Place}' (starts {live.Start:yyyy-MM-dd}).");
                }
            }
        }
    }

    // A live's nested relocations and trips must each sit within its own range; recurse for depth.
    private static void ValidateLive(Live live, Itinerary itinerary)
    {
        foreach (var nested in live.Lives)
        {
            if (nested.Start < live.Start || nested.End > live.End)
            {
                itinerary.Errors.Add(
                    $"line {nested.Line}: live '{nested.Place}' ({nested.Start:yyyy-MM-dd}..{nested.End:yyyy-MM-dd}) falls outside its live in '{live.Place}' ({live.Start:yyyy-MM-dd}..{live.End:yyyy-MM-dd}).");
            }

            ValidateLive(nested, itinerary);
        }

        foreach (var travel in live.Travels)
        {
            ValidateTravel(travel, live.Place, live.Start, live.End, "live", itinerary);
        }
    }

    // A travel — and any sub-trip nested under it — must sit within its parent's range.
    private static void ValidateTravel(Travel travel, string parentPlace, DateOnly parentStart, DateOnly parentEnd, string parentKind, Itinerary itinerary)
    {
        if (travel.Start < parentStart || travel.End > parentEnd)
        {
            itinerary.Errors.Add(
                $"line {travel.Line}: travel '{travel.Place}' ({travel.Start:yyyy-MM-dd}..{travel.End:yyyy-MM-dd}) falls outside its {parentKind} in '{parentPlace}' ({parentStart:yyyy-MM-dd}..{parentEnd:yyyy-MM-dd}).");
        }

        foreach (var nested in travel.Travels)
        {
            ValidateTravel(nested, travel.Place, travel.Start, travel.End, "travel", itinerary);
        }
    }
}
