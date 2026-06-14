namespace hop;

// long → red arrow (relocate and live there); short → blue arrow (temporary trip, then return).
public enum HopKind
{
    Long,
    Short,
}

// A point on a tour (a short hop's extra leg). The hop's own Lat/Lon is the first place; Via holds
// the ordered places after it (home is implicit at both ends).
public record Waypoint(double Lat, double Lon);

public record Hop(DateOnly Date, double Lat, double Lon, HopKind Kind, IReadOnlyList<Waypoint> Via);

public record Character(string Name, IReadOnlyList<Hop> Hops);
