using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

#region Constants
//const string ReposRoot = @"C:\git";
const string ReposRoot = @"R:\GitHub";
const string WordListFilePath = ReposRoot + @"\Programming_Scripting\C#\ScrabbleHelper\EnUsTwl.txt";
#endregion Constants

List<string>[] index = null;

// this one would be used the most.
void AnchoredLookupAndPrint(
    string chars,
    string pattern,
    string wordListFile = WordListFilePath,
    bool forceRead = false,
    Func<string, string, bool, IEnumerable<string>> lookup = null)
{
    var foundWords = AnchoredLookup(chars, pattern, wordListFile, forceRead, lookup);
    Print(foundWords);
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
    var intersection = new HashSet<string>(index[uniqChars.First() - 'a']);
    foreach (var c in uniqChars)
    {
        // Runs one more iteration than necessary.
        intersection.IntersectWith(index[c - 'a']);
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
        union.UnionWith(index[c - 'a']);
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
    var wordsList = words.ToList();
    wordsList.Sort();   // TODO: sort by score
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
    if (index == null || forceRead)
    {
        var words = File.ReadAllLines(wordListFile);
        index = new List<string>[26];
        foreach (var word in words)
        {
            var lword = word.ToLower();
            //Console.WriteLine($"{lword} ");
            var keys = lword.Distinct();
            foreach (var key in keys)
            {
                if (!(key >= 'a' && key <= 'z'))    // TODO: need to fix this to support non-English dictionaries
                {
                    continue;
                }

                if (index[key - 'a'] == null)
                {
                    index[key - 'a'] = new List<string>();
                }

                index[key - 'a'].Add(lword);
            }
        }

        foreach (var i in index)
        {
            //Console.WriteLine(i.Count());
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