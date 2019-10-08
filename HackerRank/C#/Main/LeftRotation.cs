using System;
using System.Collections.Generic;
using System.Text;

namespace Main
{
    using System.Linq;

    public class LeftRotation
    {
        public static void Runner()
        {
            var nd = Console.ReadLine().Split(' ').Select(int.Parse);
            var arr = Console.ReadLine().Split(' ').Select(s => int.Parse((string)s)).ToArray();
            var newArr = Logic(arr, nd.Last());
            Console.WriteLine(string.Join<int>(" ", newArr));
        }

        public static IEnumerable<int> Logic(int[] arr, int d)
        {
            var l = arr.Length;
            var rotations = d % l;
            foreach (var i in arr.Skip(rotations))
            {
                yield return i;
            }

            foreach (var i in arr.Take(rotations))
            {
                yield return i;
            }
        }
    }
}
