using geocode;
using Xunit;

namespace geocode.Tests;

public class ItineraryValidatorTests
{
    private static Itinerary ParseAndValidate(params string[] lines)
    {
        var itinerary = ItineraryParser.Parse(lines);
        ItineraryValidator.Validate(itinerary);
        return itinerary;
    }

    [Fact]
    public void AcceptsTravelWithinItsLive()
    {
        var itinerary = ParseAndValidate(
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-01 .. 2000-03-10");

        Assert.Empty(itinerary.Errors);
    }

    [Fact]
    public void RejectsTravelOutsideItsLive()
    {
        var itinerary = ParseAndValidate(
            "live, Northtown, 2000-01-01 .. 2000-06-01",
            "    travel, Southtown, 2000-09-01 .. 2000-09-10");

        Assert.Contains(itinerary.Errors, e => e.Contains("falls outside its live"));
    }

    [Fact]
    public void WarnsOnGapBetweenLives()
    {
        var itinerary = ParseAndValidate(
            "live, Northtown, 2000-01-01 .. 2000-06-01",
            "live, Eastville, 2000-08-01 .. 2000-12-31");

        Assert.Empty(itinerary.Errors);
        Assert.Contains(itinerary.Warnings, w => w.Contains("gap"));
    }

    [Fact]
    public void WarnsOnOverlapBetweenLives()
    {
        var itinerary = ParseAndValidate(
            "live, Northtown, 2000-01-01 .. 2000-06-01",
            "live, Eastville, 2000-05-01 .. 2000-12-31");

        Assert.Contains(itinerary.Warnings, w => w.Contains("overlap"));
    }

    [Fact]
    public void NoWarningWhenLivesAreContiguous()
    {
        var itinerary = ParseAndValidate(
            "live, Northtown, 2000-01-01 .. 2000-06-01",
            "live, Eastville, 2000-06-01 .. 2000-12-31");

        Assert.Empty(itinerary.Errors);
        Assert.Empty(itinerary.Warnings);
    }

    [Fact]
    public void AcceptsNestedLiveWithinItsParent()
    {
        var itinerary = ParseAndValidate(
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    live, Southtown, 2000-04-01 .. 2000-06-01");

        Assert.Empty(itinerary.Errors);
    }

    [Fact]
    public void RejectsNestedLiveOutsideItsParent()
    {
        var itinerary = ParseAndValidate(
            "live, Northtown, 2000-01-01 .. 2000-06-01",
            "    live, Southtown, 2000-05-01 .. 2000-09-01");

        Assert.Contains(itinerary.Errors, e => e.Contains("falls outside its live"));
    }

    [Fact]
    public void RejectsNestedTravelOutsideItsParentTravel()
    {
        var itinerary = ParseAndValidate(
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-01 .. 2000-03-20",
            "        travel, Westburg, 2000-03-05 .. 2000-04-10");

        Assert.Contains(itinerary.Errors, e => e.Contains("falls outside its travel"));
    }

    [Fact]
    public void AcceptsNestedSubTripStartingOnItsParentStartDay()
    {
        // A sub-trip may begin on the very first day of its parent (boundary, not "outside").
        var itinerary = ParseAndValidate(
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-06 .. 2000-03-14",
            "        travel, Westburg, 2000-03-06 .. 2000-03-08");

        Assert.Empty(itinerary.Errors);
    }

    // A realistic shape: sequential homes, a nested relocation, a nested sub-trip, and a
    // date-contiguous travel chain — all valid, so neither errors nor gap/overlap warnings.
    [Fact]
    public void AcceptsARealisticNestedItineraryWithoutErrorsOrWarnings()
    {
        var itinerary = ParseAndValidate(
            "live, Alpha, 2000-01-01 .. 2000-06-01",
            "live, Beta, 2000-06-01 .. 2001-06-01",
            "    live, Gamma, 2000-09-01 .. 2000-11-01",
            "    travel, Delta, 2001-01-10 .. 2001-01-20",
            "        travel, Epsilon, 2001-01-12 .. 2001-01-15",
            "    travel, Zeta, 2001-03-01 .. 2001-03-08",
            "    travel, Eta, 2001-03-08 .. 2001-03-15",
            "live, Theta, 2001-06-01 .. 2002-01-01");

        Assert.Empty(itinerary.Errors);
        Assert.Empty(itinerary.Warnings);
        Assert.Equal(3, itinerary.Lives.Count);
    }
}
