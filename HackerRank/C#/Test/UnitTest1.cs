using Microsoft.VisualStudio.TestTools.UnitTesting;
using Main;

namespace MainTest
{
    using System.Collections.Generic;
    using System.Linq;

    using FluentAssertions;

    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void CutSticksTest()
        {
            CutSticks.CutSticksLogic(new[] { 1, 2, 3, 4, 3, 3, 2, 1 }).Should().Equal(new[] { 8, 6, 4, 1 });
        }

        [TestMethod]
        public void LeftRotationTest()
        {
            LeftRotation.Logic(new[] { 1, 2, 3, 4, 5 }, 4).Should().Equal(new[] { 5, 1, 2, 3, 4 });
        }

        [TestMethod]
        public void NameTest()
        {
            new Name("Lala XI").NumVal.Should().Be(11);
            new Name("lkj XLVII").NumVal.Should().Be(47);
        }

        [TestMethod]
        public void RomanTest()
        {
            Roman.Logic(new List<string>(new []{ "Louis IX", "Louis VIII"})).Should().Equal(new[]{"Louis VIII", "Louis IX"});
        }

        [TestMethod]
        public void JanitorTest()
        {
            Janitor.Logic(new[]
                              {
                                  1.5f,
                                  1.5f,
                                  1.5f,
                                  1.5f,
                              }.ToList()).Should().Be(2);
            Janitor.Logic(new[]
                              {
                                  1.5f,
                                  1.5f,
                                  1.5f,
                                  1.5f,
                                  1.5f,
                              }.ToList()).Should().Be(3);
            Janitor.Logic(new[]
                              {
                                  1.01f,
                                  1.99f,
                                  2.5f,
                                  1.5f,
                                  1.01f,
                              }.ToList()).Should().Be(3);
        }
    }
}
