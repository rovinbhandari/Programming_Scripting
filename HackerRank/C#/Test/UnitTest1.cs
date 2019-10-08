using Microsoft.VisualStudio.TestTools.UnitTesting;
using Main;

namespace MainTest
{
    using FluentAssertions;

    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void CutSticksTest()
        {
            CutSticks.CutSticksLogic(new[] { 1, 2, 3, 4, 3, 3, 2, 1 }).Should().BeEquivalentTo(new[] { 8, 6, 4, 1 });
        }
    }
}
