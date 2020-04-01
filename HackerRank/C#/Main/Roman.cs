using System;
using System.Collections.Generic;
using System.Text;

namespace Main
{
    using System.Linq;

    public class Roman
    {
        public static void Runner()
        {
            var n = int.Parse(Console.ReadLine());
            var names = new List<string>(n);
            for (int i = 0; i < n; i++)
            {
                names.Add(Console.ReadLine());
            }

            var sorted = Logic(names);
            foreach (var name in sorted)
            {
                Console.WriteLine(name);
            }
        }

        public static List<string> Logic(List<string> names)
        {
            var nameObjs = names.Select(n => new Name(n));
            var sortedObjs = nameObjs.OrderBy(n => n, new NameComparer());
                return sortedObjs.Select(n => $"{n.Given} {n.Num}").ToList();
        }
    }

    public class Name
    {
        public string Given { get; set; }

        public string Num { get; set; }

        public int NumVal { get; set; }

        public Name(string n)
        {
            var split = n.Split(' ');
            this.Given = split[0];
            this.Num = split[1];
            this.NumVal = GetVal(split[1]);
        }



        public int GetVal(string n)
        {
            var dict = new Dictionary<char, int> { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 } };
            var sum = 0;
            for (int i = 0; i < n.Length; i++)
            {
                if (i < n.Length - 1 && dict[n[i]] < dict[n[i + 1]])
                {
                    sum += (dict[n[i + 1]] - dict[n[i]]);
                    i++;
                }
                else
                {
                    sum += dict[n[i]];
                }
            }

            return sum;
        }
    }

    public class NameComparer : IComparer<Name>
    {
        public int Compare(Name x, Name y)
        {
            var gc = x.Given.CompareTo(y.Given);
            if (gc != 0)
                return gc;
            else
            {
                return x.NumVal.CompareTo(y.NumVal);
            }
        }
    }
}
