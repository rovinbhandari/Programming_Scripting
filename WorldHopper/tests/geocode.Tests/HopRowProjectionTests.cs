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

    [Fact]
    public void ProjectsNestedLiveAsRedHopOutAndBack()
    {
        var itinerary = ItineraryParser.Parse(new[]
        {
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    live, Southtown, 2000-04-01 .. 2000-06-01",
        });

        var rows = itinerary.ToHopRows();

        Assert.Collection(
            rows,
            r => Assert.Equal(new HopRow(new DateOnly(2000, 1, 1), "Northtown", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 4, 1), "Southtown", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 6, 1), "Northtown", "long"), r));
    }

    [Fact]
    public void ChainsDateContiguousNestedLivesBeforeReturning()
    {
        var itinerary = ItineraryParser.Parse(new[]
        {
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    live, Southtown, 2000-03-01 .. 2000-05-01",
            "    live, Westburg, 2000-05-01 .. 2000-07-01",
        });

        var rows = itinerary.ToHopRows();

        Assert.Collection(
            rows,
            r => Assert.Equal(new HopRow(new DateOnly(2000, 1, 1), "Northtown", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 3, 1), "Southtown", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 5, 1), "Westburg", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 7, 1), "Northtown", "long"), r));
    }

    [Fact]
    public void ChainsContiguousSiblingTravelsIntoOneTour()
    {
        var itinerary = ItineraryParser.Parse(new[]
        {
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-01 .. 2000-03-10",
            "    travel, Westburg, 2000-03-10 .. 2000-03-20",
        });

        var rows = itinerary.ToHopRows();

        Assert.Collection(
            rows,
            r => Assert.Equal(new HopRow(new DateOnly(2000, 1, 1), "Northtown", "long"), r),
            r => AssertTour(r, new DateOnly(2000, 3, 1), "Southtown", "Westburg"));
    }

    [Fact]
    public void KeepsNonContiguousSiblingTravelsAsSeparateTours()
    {
        var itinerary = ItineraryParser.Parse(new[]
        {
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-01 .. 2000-03-10",
            "    travel, Westburg, 2000-05-01 .. 2000-05-20",
        });

        var rows = itinerary.ToHopRows();

        Assert.Collection(
            rows,
            r => Assert.Equal(new HopRow(new DateOnly(2000, 1, 1), "Northtown", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 3, 1), "Southtown", "short"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 5, 1), "Westburg", "short"), r));
    }

    [Fact]
    public void SplicesNestedSubTripWithReturnToBase()
    {
        var itinerary = ItineraryParser.Parse(new[]
        {
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-01 .. 2000-04-01",
            "        travel, Westburg, 2000-03-10 .. 2000-03-20",
        });

        var rows = itinerary.ToHopRows();

        Assert.Collection(
            rows,
            r => Assert.Equal(new HopRow(new DateOnly(2000, 1, 1), "Northtown", "long"), r),
            r => AssertTour(r, new DateOnly(2000, 3, 1), "Southtown", "Westburg", "Southtown"));
    }

    [Fact]
    public void SplitsNonContiguousSubTripsWithBaseRevisits()
    {
        var itinerary = ItineraryParser.Parse(new[]
        {
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-01 .. 2000-04-01",
            "        travel, Westburg, 2000-03-05 .. 2000-03-10",
            "        travel, Easton, 2000-03-20 .. 2000-03-25",
        });

        var rows = itinerary.ToHopRows();

        Assert.Collection(
            rows,
            r => Assert.Equal(new HopRow(new DateOnly(2000, 1, 1), "Northtown", "long"), r),
            r => AssertTour(r, new DateOnly(2000, 3, 1), "Southtown", "Westburg", "Southtown", "Easton", "Southtown"));
    }

    [Fact]
    public void SortsOutOfOrderSiblingTravelsChronologically()
    {
        // Siblings may be listed out of date order; tours are emitted sorted by start date.
        var itinerary = ItineraryParser.Parse(new[]
        {
            "live, Northtown, 2000-01-01 .. 2002-01-01",
            "    travel, Beta, 2001-06-01 .. 2001-06-10",
            "    travel, Alpha, 2000-03-01 .. 2000-03-10",
        });

        var rows = itinerary.ToHopRows();

        Assert.Collection(
            rows,
            r => Assert.Equal(new HopRow(new DateOnly(2000, 1, 1), "Northtown", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 3, 1), "Alpha", "short"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2001, 6, 1), "Beta", "short"), r));
    }

    [Fact]
    public void ProjectsTwoNonContiguousNestedLivesAsSeparateRelocations()
    {
        // Two relocations with a gap each go out and return to the base in between.
        var itinerary = ItineraryParser.Parse(new[]
        {
            "live, Northtown, 2000-01-01 .. 2003-01-01",
            "    live, Southtown, 2000-06-01 .. 2000-09-01",
            "    live, Westburg, 2001-06-01 .. 2001-09-01",
        });

        var rows = itinerary.ToHopRows();

        Assert.Collection(
            rows,
            r => Assert.Equal(new HopRow(new DateOnly(2000, 1, 1), "Northtown", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 6, 1), "Southtown", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2000, 9, 1), "Northtown", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2001, 6, 1), "Westburg", "long"), r),
            r => Assert.Equal(new HopRow(new DateOnly(2001, 9, 1), "Northtown", "long"), r));
    }

    // HopRow records compare the Extra list by reference, so assert tour rows by their ordered
    // place list (Place + Extra) instead of constructing an expected row.
    private static void AssertTour(HopRow row, DateOnly date, params string[] places)
    {
        Assert.Equal(date, row.Date);
        Assert.Equal("short", row.Kind);
        Assert.Equal(places, row.AllPlaces);
    }
}
