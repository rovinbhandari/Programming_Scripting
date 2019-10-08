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
            CutSticks.CutSticksLogic(new[] { 1, 2, 3, 4, 3, 3, 2, 1 }).Should().Equal(new[] { 8, 6, 4, 1 });
        }

        [TestMethod]
        public void LeftRotationTest()
        {
            LeftRotation.Logic(new[] { 1, 2, 3, 4, 5 }, 4).Should().Equal(new[] { 5, 1, 2, 3, 4 });
        }
    }
}
