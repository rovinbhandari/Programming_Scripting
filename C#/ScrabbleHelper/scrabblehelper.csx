using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

#region Constants
//const string ReposRoot = @"C:\git";
const string ReposRoot = @"R:\GitHub";
//const string WordListFilePath = ReposRoot + @"\Programming_Scripting\C#\ScrabbleHelper\NbNoNsf.txt";
const string WordListFilePath = ReposRoot + @"\Programming_Scripting\C#\ScrabbleHelper\EnUsTwl.txt";
const string Alpha = "abcdefghijklmnopqrstuvwxyzæøå";
#endregion Constants

List<string>[] hash = null;

// TODO: make it runnable with Roslyn\csc.exe from console
// TODO: refactor so that different languages can be used in the same session

// this one would be used the most.
void AnchoredLookupAndPrint(
    string chars,
    string pattern,
    string wordListFile = WordListFilePath,
    bool forceRead = false,
    Func<string, string, bool, IEnumerable<string>> lookup = null)
{
    if (!chars.Contains(' '))
    {
        var foundWords = AnchoredLookup(chars, pattern, wordListFile, forceRead, lookup);
        Print(foundWords);
    }
    else    // TODO: this should be handled by AnchoredLookup(...) instead.
    {
        var allFoundWords = new List<string>();
        chars = chars.Replace(" ", "");
        foreach(var l in Alpha.ToCharArray())
        {
            allFoundWords.AddRange(AnchoredLookup(chars + l, pattern, wordListFile, forceRead, lookup));
        }

        Print(allFoundWords);
    }
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
    string wordListFile = WordListFilePath,
    bool forceRead = false,
    Func<string, string, bool, IEnumerable<string>> lookup = null)
{
    if (lookup == null)
    {
        lookup = LookupUnion;
    }

    var wordsWithProvidedChars = lookup(chars, wordListFile, forceRead);
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
    string wordListFile = WordListFilePath,
    bool forceRead = false)
{
    var uniqChars = GetUniqChars(chars);
    CreateIndex(wordListFile, forceRead);
    var intersection = new HashSet<string>(hash[Alpha.IndexOf(uniqChars.First())]);
    foreach (var c in uniqChars)
    {
        // Runs one more iteration than necessary.
        intersection.IntersectWith(hash[Alpha.IndexOf(c)]);
    }

    return intersection;
}

IEnumerable<string> LookupUnion(
    string chars,
    string wordListFile = WordListFilePath,
    bool forceRead = false)
{
    var uniqChars = GetUniqChars(chars);
    CreateIndex(wordListFile, forceRead);
    var union = new HashSet<string>();
    foreach (var c in uniqChars)
    {
        union.UnionWith(hash[Alpha.IndexOf(c)]);
    }

    return union;
}

void LookupAndPrint(
    string chars,
    Func<string, string, bool, IEnumerable<string>> lookup = null,
    string wordListFile = WordListFilePath,
    bool forceRead = false)
{
    if (lookup == null)
    {
        lookup = LookupIntersection;
    }

    var foundWords = lookup(chars, wordListFile, forceRead);
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
    string wordListFile = WordListFilePath,
    bool forceRead = false)
{
    if (hash == null || forceRead)
    {
        var words = File.ReadAllLines(wordListFile);
        hash = new List<string>[Alpha.Length];
        foreach (var word in words)
        {
            var lword = word.ToLower();
            //Console.WriteLine($"{lword} ");
            var keys = lword.Distinct();
            foreach (var key in keys)
            {
                if (!(Alpha.Contains(key)))
                {
                    continue;
                }

                var index = Alpha.IndexOf(key);
                if (hash[index] == null)
                {
                    hash[index] = new List<string>();
                }

                hash[index].Add(lword);
            }
        }

        foreach (var i in hash)
        {
            Console.WriteLine(i?.Count());
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