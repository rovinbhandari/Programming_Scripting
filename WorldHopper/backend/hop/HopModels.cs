namespace hop;

// long → red arrow (relocate and live there); short → blue arrow (temporary trip, then return).
public enum HopKind
{
    Long,
    Short,
}

public record Hop(DateOnly Date, double Lat, double Lon, HopKind Kind);

public record Character(string Name, IReadOnlyList<Hop> Hops);
