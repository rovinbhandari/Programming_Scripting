using System.Text.Json;
using geocode;
using Xunit;

namespace geocode.Tests;

// Covers the result-selection heuristic that keeps a populated-place node from being
// passed over in favour of an offshore region/water polygon (which Nominatim may rank first).
public class GeocoderSelectionTests
{
    private static NominatimResult Result(string category, string type, double importance, double lat = 0, double lon = 0)
        => new(lat, lon, $"{category}/{type}", category, type, importance);

    [Theory]
    [InlineData("place", "city", 3)]
    [InlineData("place", "village", 3)]
    [InlineData("place", "hamlet", 3)]
    [InlineData("place", "island", 2)]
    [InlineData("boundary", "administrative", 1)]
    [InlineData("highway", "residential", 0)]
    [InlineData("natural", "bay", -1)]
    [InlineData("waterway", "river", -1)]
    public void ScoreRanksLandSettlementsHighestAndWaterLowest(string category, string type, int expected)
    {
        Assert.Equal(expected, Geocoder.Score(category, type));
    }

    [Theory]
    [InlineData("sea")]
    [InlineData("ocean")]
    [InlineData("strait")]
    public void ScoreDemotesWaterTypesEvenWhenClassedAsPlace(string type)
    {
        Assert.Equal(-1, Geocoder.Score("place", type));
    }

    [Fact]
    public void SelectBestPrefersLandNodeOverHigherRankedOffshorePolygon()
    {
        var best = Geocoder.SelectBest(new[]
        {
            Result("natural", "bay", importance: 0.90, lat: 1.5, lon: 2.5),
            Result("place", "town", importance: 0.30, lat: 1.0, lon: 2.0),
        });

        Assert.NotNull(best);
        Assert.Equal("place", best!.Category);
        Assert.Equal(1.0, best.Lat);
        Assert.Equal(2.0, best.Lon);
    }

    [Fact]
    public void SelectBestBreaksTiesByNominatimImportance()
    {
        var best = Geocoder.SelectBest(new[]
        {
            Result("place", "city", importance: 0.40, lat: 10, lon: 10),
            Result("place", "city", importance: 0.90, lat: 20, lon: 20),
        });

        Assert.Equal(20, best!.Lat);
    }

    [Fact]
    public void SelectBestKeepsTheFirstCandidateWhenScoreAndImportanceAreEqual()
    {
        var best = Geocoder.SelectBest(new[]
        {
            Result("place", "city", importance: 0.50, lat: 10, lon: 10),
            Result("place", "city", importance: 0.50, lat: 20, lon: 20),
        });

        Assert.Equal(10, best!.Lat);
    }

    [Fact]
    public void SelectBestReturnsNullForNoCandidates()
    {
        Assert.Null(Geocoder.SelectBest(System.Array.Empty<NominatimResult>()));
    }

    [Fact]
    public void ParseResultsReadsFieldsAndSkipsMalformedEntries()
    {
        const string json = """
        [
            { "lat": "oops", "lon": "2.0", "class": "place", "type": "city" },
            { "lon": "2.0", "class": "place", "type": "city" },
            { "lat": "1.0", "lon": "2.0", "display_name": "Goodtown", "class": "place", "type": "town", "importance": 0.5 }
        ]
        """;
        using var document = JsonDocument.Parse(json);

        var results = Geocoder.ParseResults(document.RootElement);

        var only = Assert.Single(results);
        Assert.Equal(1.0, only.Lat);
        Assert.Equal(2.0, only.Lon);
        Assert.Equal("Goodtown", only.DisplayName);
        Assert.Equal("place", only.Category);
        Assert.Equal("town", only.Type);
        Assert.Equal(0.5, only.Importance);
    }

    [Fact]
    public void ParseResultsDefaultsMissingImportanceToZero()
    {
        const string json = """
        [ { "lat": "3.0", "lon": "4.0", "class": "place", "type": "village" } ]
        """;
        using var document = JsonDocument.Parse(json);

        var only = Assert.Single(Geocoder.ParseResults(document.RootElement));
        Assert.Equal(0.0, only.Importance);
    }

    [Fact]
    public void SelectBestOverParsedResultsPicksTheTownOverTheBay()
    {
        const string json = """
        [
            { "lat": "1.5", "lon": "2.5", "display_name": "Harbour Bay", "class": "natural", "type": "bay", "importance": 0.8 },
            { "lat": "1.0", "lon": "2.0", "display_name": "Harbourville", "class": "place", "type": "town", "importance": 0.4 }
        ]
        """;
        using var document = JsonDocument.Parse(json);

        var best = Geocoder.SelectBest(Geocoder.ParseResults(document.RootElement));

        Assert.Equal("Harbourville", best!.DisplayName);
    }
}
