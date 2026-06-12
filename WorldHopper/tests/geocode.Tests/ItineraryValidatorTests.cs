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
}
