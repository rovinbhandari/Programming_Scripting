using geocode;
using Xunit;

namespace geocode.Tests;

public class HopRowProjectionTests
{
    [Fact]
    public void ProjectsLivesAsLongAndTravelsAsShortSortedByDate()
    {
        var itinerary = ItineraryParser.Parse(new[]
        {
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-01 .. 2000-03-10",
            "live, Eastville, 2000-12-31 .. 2001-06-01",
        });

        var rows = itinerary.ToHopRows();

        Assert.Collection(
            rows,
            r => Assert.Equal(new HopRow(new DateOnly(2000, 1, 1), "Northtown", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 3, 1), "Southtown", "short"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 12, 31), "Eastville", "long"), r));
    }
}
