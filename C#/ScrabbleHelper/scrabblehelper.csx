using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Collections.Concurrent;
using System.Threading.Tasks;
using System;

#region Constants
//const string ReposRoot = @"C:\git";
const string ReposRoot = @"R:\GitHub";
string[] WordListFilePaths = new[] {
    ReposRoot + @"\Programming_Scripting\C#\ScrabbleHelper\EnUsTwl.txt",
    ReposRoot + @"\Programming_Scripting\C#\ScrabbleHelper\NbNoNsf.txt"
};
string[] Alpha = new[] {
    "abcdefghijklmnopqrstuvwxyz",
    "abcdefghijklmnopqrstuvwxyzæøå"
};
const int MaxChars = 50;
enum Lang { en, nb }
#endregion Constants

List<string>[] hash = null;
Lang prevLang = Lang.en;

// TODO: make it runnable with Roslyn\csc.exe from console

// this one would be used the most.
void AnchoredLookupAndPrint(
    string chars,
    string pattern,
    string language = "en",
    bool forceRead = false,
    Func<string, Lang, bool, IEnumerable<string>> lookup = null)
{
    if (!Enum.TryParse(language, out Lang lang))
        throw new Exception("unknown language");
    forceRead = forceRead || lang != prevLang;
    if (!chars.Contains(' '))
    {
        var foundWords = AnchoredLookup(chars, pattern, lang, forceRead, lookup);
        Print(foundWords);
    }
    else    // TODO: this should be handled by AnchoredLookup(...) instead.
    {
        var allFoundWords = new ConcurrentBag<string>();
        chars = chars.Replace(" ", "");
        try
        {
            CreateIndex(lang, forceRead);
            Parallel.ForEach(Alpha[(int)lang].ToCharArray(), l =>
            {
                var words = AnchoredLookup(chars + l, pattern, lang, false, lookup);
                foreach (var w in words)
                    allFoundWords.Add(w);
            });
        }
        catch(AggregateException ae)
        {
            ae.Handle(e =>
            {
                Console.WriteLine($"{e}; {e.Message}; {e.InnerException}");
                return true;
            });
        }
        catch(ArgumentException re)
        {
            Console.WriteLine($"{re}; {re.Message}");
        }

        Print(allFoundWords.ToArray());
    }

    prevLang = lang;
}

// pattern can be of the form: *.x.*.y.*
// where, * is any number of any characters
// . matches one of the provied characters
// x and y are fixed characters (anchors)
// * can be replaced with # to match any number of provided characters
// . can be replaced with ? to match 0 or 1 times one of the provided characters
// TODO: * is not supported with the current filtering.
IEnumerable<string> AnchoredLookup(
    string chars,
    string pattern,
    Lang lang = Lang.en,
    bool forceRead = false,
    Func<string, Lang, bool, IEnumerable<string>> lookup = null)
{
    if (lookup == null)
    {
        lookup = LookupUnion;
    }

    var wordsWithProvidedChars = lookup(chars, lang, forceRead);
    var regexPattern = "\\b" + pattern.Replace(".", $"[{chars}]{{1}}").Replace("?", $"[{chars}]?").Replace("*", "\\w*").Replace("#", $"[{chars}]*") + "\\b";
    Console.WriteLine($"Using pattern to search: {regexPattern}");
    var regex = new Regex(regexPattern);
    var allowedChars = chars + pattern;

    // remove words which do not match the regex
    // remove words which have more character repetitions than allowed in chars
    // TODO: optimize the filtering below!
    return wordsWithProvidedChars
           .Where(word => regex.IsMatch(word))
           .Where(word =>
               {
                   foreach (var c in word.Distinct())
                   {
                       if (word.Count(ch => ch == c) > allowedChars.Count(ch => ch == c))
                           return false;
                   }
                   return true;
               }); 
}

IEnumerable<string> LookupIntersection(
    string chars,
    Lang lang = Lang.en,
    bool forceRead = false)
{
    var uniqChars = GetUniqChars(chars);
    CreateIndex(lang, forceRead);
    var intersection = new HashSet<string>(hash[Alpha[(int)lang].IndexOf(uniqChars.First())]);
    foreach (var c in uniqChars)
    {
        // Runs one more iteration than necessary.
        intersection.IntersectWith(hash[Alpha[(int)lang].IndexOf(c)]);
    }

    return intersection;
}

IEnumerable<string> LookupUnion(
    string chars,
    Lang lang = Lang.en,
    bool forceRead = false)
{
    var uniqChars = GetUniqChars(chars);
    CreateIndex(lang, forceRead);
    var union = new HashSet<string>();
    foreach (var c in uniqChars)
    {
        union.UnionWith(hash[Alpha[(int)lang].IndexOf(c)]);
    }

    return union;
}

void LookupAndPrint(
    string chars,
    Func<string, Lang, bool, IEnumerable<string>> lookup = null,
    Lang lang = Lang.en,
    bool forceRead = false)
{
    if (lookup == null)
    {
        lookup = LookupIntersection;
    }

    var foundWords = lookup(chars, lang, forceRead);
    Print(foundWords);
}

void Print(IEnumerable<string> words)
{
    var wordsList = words.Distinct().ToList();
    wordsList.Sort();   // TODO: append score
    var wordsArray = wordsList.ToArray();
    Console.WriteLine($"Found {wordsArray.Length} matches.");
    for(var i = 0; i < wordsArray.Length; i+= 3)
    {
        Console.WriteLine(
            string.Format(
                "{0,-40}\t{1,-40}\t{2}",
                ArrayLookup(wordsArray, i),
                ArrayLookup(wordsArray, i + 1),
                ArrayLookup(wordsArray, i + 2)));
    }
}

#region Privates
private string ArrayLookup(string[] arr, int index)
{
    if(index >= arr.Length)
    {
        return null;
    }
    else
    {
        return arr[index];
    }
}

private void CreateIndex(
    Lang lang = Lang.en,
    bool forceRead = false)
{
    if (hash == null || forceRead)
    {
        var words = File.ReadAllLines(WordListFilePaths[(int)lang]);
        hash = new List<string>[MaxChars];
        foreach (var word in words)
        {
            var lword = word.ToLower();
            //Console.WriteLine($"{lword} ");
            var keys = lword.Distinct();
            foreach (var key in keys)
            {
                if (!(Alpha[(int)lang].Contains(key)))
                {
                    continue;
                }

                var index = Alpha[(int)lang].IndexOf(key);
                if (hash[index] == null)
                {
                    hash[index] = new List<string>();
                }

                hash[index].Add(lword);
            }
        }

        foreach (var i in hash)
        {
            //Console.WriteLine(i?.Count());
        }
    }
}

private IEnumerable<char> GetUniqChars(string chars)
{
    var uniqChars = chars.Distinct();
    if (uniqChars.Count() < 1)
    {
        throw new System.Exception("Too few characters. Need at least 1");
    }

    return uniqChars;
}
#endregion Privates