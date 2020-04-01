using System;
using System.Collections.Generic;
using System.Text;

namespace Main
{
    using System.Linq;
    using System.Text.RegularExpressions;

   public class Janitor
    {
        public static void Runner()
        {
        }

        private const float maxBinSize = 3.0f;

        public static int Logic(List<float> weight)
        {
            var weights = weight.Count;
            var weightDec = weight.OrderByDescending(x => x).ToArray();
            var bins = 0;
            var bincaprem = new int[weights].Select(x => maxBinSize).ToList();
            for (int i = 0; i < weights; i++)
            {
                var binindex = 0;
                for (; binindex < bins; binindex++)
                {
                    if (bincaprem[binindex] >= weightDec[i])
                    {
                        bincaprem[binindex] -= weightDec[i];
                        break;
                    }

                }

                if (binindex == bins)
                {
                    bincaprem[binindex] = maxBinSize - weightDec[i];
                    bins++;
                }
            }

            return bins;    
        }
    }
}
