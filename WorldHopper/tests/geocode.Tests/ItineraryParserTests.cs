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
    public void ParsesRangeWithSpaceOnlyOnOneSideOfSeparator()
    {
        // A real file mixes spacing, e.g. "2000-01-01 ..2000-06-01" (space before, none after).
        var itinerary = Parse("live, Northtown, 2000-01-01 ..2000-06-01");

        Assert.Empty(itinerary.Errors);
        var live = Assert.Single(itinerary.Lives);
        Assert.Equal(new DateOnly(2000, 1, 1), live.Start);
        Assert.Equal(new DateOnly(2000, 6, 1), live.End);
    }

    [Fact]
    public void ReportsEmptyPlaceName()
    {
        var itinerary = Parse("live, , 2000-01-01 .. 2000-06-01");

        Assert.Empty(itinerary.Lives);
        Assert.Contains(itinerary.Errors, e => e.Contains("place name is empty"));
    }

    // Indentation is significant: a dedent must reattach to the nearest shallower ancestor,
    // popping past any deeper entries (here the second trip returns to the live, not the sub-trip).
    [Fact]
    public void DedentReattachesEntryToShallowerAncestor()
    {
        var itinerary = Parse(
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-01 .. 2000-03-14",
            "        travel, Westburg, 2000-03-02 .. 2000-03-08",
            "    travel, Eastville, 2000-06-01 .. 2000-06-10");

        Assert.Empty(itinerary.Errors);
        var home = Assert.Single(itinerary.Lives);
        Assert.Collection(
            home.Travels,
            southtown =>
            {
                Assert.Equal("Southtown", southtown.Place);
                Assert.Equal("Westburg", Assert.Single(southtown.Travels).Place);
            },
            eastville =>
            {
                Assert.Equal("Eastville", eastville.Place);
                Assert.Empty(eastville.Travels);
            });
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

    [Fact]
    public void ParsesNestedLiveAsTemporaryRelocation()
    {
        var itinerary = Parse(
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    live, Southtown, 2000-04-01 .. 2000-06-01");

        Assert.Empty(itinerary.Errors);
        var home = Assert.Single(itinerary.Lives);
        var relocation = Assert.Single(home.Lives);
        Assert.Equal("Southtown", relocation.Place);
        Assert.Empty(home.Travels);
    }

    [Fact]
    public void ParsesTravelNestedUnderAnotherTravel()
    {
        var itinerary = Parse(
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-01 .. 2000-03-20",
            "        travel, Westburg, 2000-03-05 .. 2000-03-10");

        Assert.Empty(itinerary.Errors);
        var trip = Assert.Single(Assert.Single(itinerary.Lives).Travels);
        Assert.Equal("Southtown", trip.Place);
        var subTrip = Assert.Single(trip.Travels);
        Assert.Equal("Westburg", subTrip.Place);
    }

    [Fact]
    public void SiblingTravelsAttachToTheSameLive()
    {
        var itinerary = Parse(
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-01 .. 2000-03-10",
            "    travel, Westburg, 2000-03-10 .. 2000-03-20");

        Assert.Empty(itinerary.Errors);
        var home = Assert.Single(itinerary.Lives);
        Assert.Equal(2, home.Travels.Count);
        Assert.Empty(home.Travels[0].Travels);
    }

    [Fact]
    public void RejectsLiveNestedUnderTravel()
    {
        var itinerary = Parse(
            "live, Northtown, 2000-01-01 .. 2000-12-31",
            "    travel, Southtown, 2000-03-01 .. 2000-03-20",
            "        live, Westburg, 2000-03-05 .. 2000-03-10");

        Assert.Contains(itinerary.Errors, e => e.Contains("'live' cannot be nested under a 'travel'"));
    }
}
