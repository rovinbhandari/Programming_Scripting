namespace Main
{
    using System;
    using System.Collections.Generic;
    using System.Linq;

    public class CutSticks
    {
        public static void CutSticksRunner()
        {
            var n = int.Parse(Console.ReadLine());
            var arr = Console.ReadLine().Split(' ').Select(s => int.Parse((string)s)).ToArray();
            var cuts = CutSticksLogic(arr);
            Console.WriteLine(string.Join<int>(Environment.NewLine, cuts));
        }

        public static int[] CutSticksLogic(int[] arr)
        {
            arr = arr.OrderBy(i => i).ToArray();
            var result = new List<int>();
            var remaining = arr.Length;
            while (arr.Length > 0)
            {
                result.Add(remaining);
                var skip = arr.TakeWhile(i => i == arr.First()).Count();
                remaining -= skip;
                arr = arr.Skip(skip).ToArray();
            }

            return result.ToArray();
        }
    }
}