using geocode;
using Xunit;

namespace geocode.Tests;

public class ItineraryParserTests
{
    private static Itinerary Parse(params string[] lines) => ItineraryParser.Parse(lines);

    [Fact]
    public void ParsesLivesAndNestedTravels()
    {
        var itinerary = Parse(
            "live, Northtown, 2000-01-01 .. 2000-06-01",
            "    travel, Southtown, 2000-03-01 .. 2000-03-10",
            "live, Eastville, 2000-06-01 .. 2000-12-31");

        Assert.Empty(itinerary.Errors);
        Assert.Equal(2, itinerary.Lives.Count);

        var home = itinerary.Lives[0];
        Assert.Equal("Northtown", home.Place);
        Assert.Equal(new DateOnly(2000, 1, 1), home.Start);
        Assert.Equal(new DateOnly(2000, 6, 1), home.End);

        var trip = Assert.Single(home.Travels);
        Assert.Equal("Southtown", trip.Place);
        Assert.Equal(new DateOnly(2000, 3, 1), trip.Start);

        Assert.Empty(itinerary.Lives[1].Travels);
    }

    [Fact]
    public void IgnoresCommentsAndBlankLines()
    {
        var itinerary = Parse(
            "# a comment",
            "",
            "   ",
            "live, Northtown, 2000-01-01 .. 2000-06-01");

        Assert.Empty(itinerary.Errors);
        Assert.Single(itinerary.Lives);
    }

    [Fact]
    public void KeepsCommasInsidePlaceNames()
    {
        var itinerary = Parse("live, Eastville, Republic of Test, 2000-01-01 .. 2000-06-01");

        Assert.Empty(itinerary.Errors);
        Assert.Equal("Eastville, Republic of Test", Assert.Single(itinerary.Lives).Place);
    }

    [Fact]
    public void ParsesRangeWithoutSpacesAroundSeparator()
    {
        var itinerary = Parse("live, Northtown, 2000-01-01..2000-06-01");

        Assert.Empty(itinerary.Errors);
        var live = Assert.Single(itinerary.Lives);
        Assert.Equal(new DateOnly(2000, 1, 1), live.Start);
        Assert.Equal(new DateOnly(2000, 6, 1), live.End);
    }

    [Fact]
    public void ReportsTravelBeforeAnyLive()
    {
        var itinerary = Parse("travel, Southtown, 2000-03-01 .. 2000-03-10");

        Assert.Empty(itinerary.Lives);
        Assert.Contains(itinerary.Errors, e => e.Contains("'travel' before any 'live'"));
    }

    [Fact]
    public void ReportsUnknownKeyword()
    {
        var itinerary = Parse("visit, Southtown, 2000-03-01 .. 2000-03-10");

        Assert.Contains(itinerary.Errors, e => e.Contains("'live' or 'travel'"));
    }

    [Theory]
    [InlineData("live, Northtown, 2000-01-01")]         // no range separator
    [InlineData("live, Northtown, 2000-01-01 .. nope")] // unparseable end date
    [InlineData("live, Northtown")]                     // too few fields
    public void ReportsMalformedRows(string line)
    {
        var itinerary = Parse(line);

        Assert.NotEmpty(itinerary.Errors);
        Assert.Empty(itinerary.Lives);
    }

    [Fact]
    public void ReportsStartAfterEnd()
    {
        var itinerary = Parse("live, Northtown, 2000-06-01 .. 2000-01-01");

        Assert.Contains(itinerary.Errors, e => e.Contains("is after end"));
    }
}
