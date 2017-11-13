#r "R:\CxCache\Newtonsoft.Json.9.0.1\lib\net45\Newtonsoft.Json.dll"
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

#region Constants
const string WordListFilePath = @"R:\GitHub\Programming_Scripting\C#\ScrabbleHelper\EngWordList.txt";
const string IndexListFilePath = @"R:\GitHub\Programming_Scripting\C#\ScrabbleHelper\Index.json";
#endregion Constants

List<string>[] index = null;

// this needs to run once before using any of the lookups
void CreateIndex(
    string wordListFile = WordListFilePath,
    string indexFile = IndexListFilePath)
{
    var words = File.ReadAllLines(wordListFile);
    var index = new List<string>[26];
    foreach (var word in words)
    {
        var lword = word.ToLower();
        //Console.Write($"{lword} ");
        var keys = lword.Distinct();
        foreach (var key in keys)
        {
            if (index[key - 'a'] == null)
            {
                index[key - 'a'] = new List<string>();
            }
            index[key - 'a'].Add(lword);
        }
    }

    var j = Newtonsoft.Json.JsonConvert.SerializeObject(index);
    using (var writer = new StreamWriter(indexFile))
    {
        writer.Write(j);
    }
}

IEnumerable<string> LookupIntersection(
    string chars,
    string indexFile = IndexListFilePath,
    bool forceRead = false)
{
    var uniqChars = GetUniqChars(chars);
    LoadIndex(indexFile, forceRead);
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
    string indexFile = IndexListFilePath,
    bool forceRead = false)
{
    var uniqChars = GetUniqChars(chars);
    LoadIndex(indexFile, forceRead);
    var union = new HashSet<string>();
    foreach (var c in uniqChars)
    {
        union.UnionWith(index[c - 'a']);
    }

    return union;
}

// pattern can be of the form: *.x.*.y.*
// where, * is any number of any characters
// . matches one of the provied characters
// x and y are fixed characters (anchors)
// * can be replaced with # to match any number of provided characters
// . can be replaced with ? to match 0 or 1 times one of the provided characters
IEnumerable<string> AnchoredLookup(
    string chars,
    string pattern,
    Func<string, string, bool, IEnumerable<string>> lookup = null,
    string indexFile = IndexListFilePath,
    bool forceRead = false)
{
    if (lookup == null)
    {
        lookup = LookupUnion;
    }

    var wordsWithProvidedChars = lookup(chars, indexFile, forceRead);
    var regexPattern = "\\b" + pattern.Replace(".", $"[{chars}]{{1}}").Replace("?", $"[{chars}]?").Replace("*", "\\w*").Replace("#", $"[{chars}]*") + "\\b";
    Console.WriteLine($"Using pattern to search: {regexPattern}");
    var regex = new Regex(regexPattern);
    return wordsWithProvidedChars.Where(word => regex.IsMatch(word));
}

void LookupAndPrint(
    string chars,
    Func<string, string, bool, IEnumerable<string>> lookup = null,
    string indexFile = IndexListFilePath,
    bool forceRead = false)
{
    if (lookup == null)
    {
        lookup = LookupIntersection;
    }

    var foundWords = lookup(chars, indexFile, forceRead);
    Print(foundWords);
}

// this one would be used the most.
void AnchoredLookupAndPrint(
    string chars,
    string pattern,
    Func<string, string, bool, IEnumerable<string>> lookup = null,
    string indexFile = IndexListFilePath,
    bool forceRead = false)
{
    var foundWords = AnchoredLookup(chars, pattern, lookup, indexFile, forceRead);
    Print(foundWords);
}

void Print(IEnumerable<string> words)
{
    var wordsList = words.ToList();
    wordsList.Sort();
    var wordsArray = wordsList.ToArray();
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

private void LoadIndex(
    string indexFile = IndexListFilePath,
    bool forceRead = false)
{
    if (index == null || forceRead)
    {
        if (!File.Exists(indexFile))
        {
            throw new FileNotFoundException($"index file not found @ {indexFile}");
        }

        var jsonIndex = "";
        using (var reader = new StreamReader(indexFile))
        {
            jsonIndex = reader.ReadToEnd();
        }

        index = Newtonsoft.Json.JsonConvert.DeserializeObject<List<string>[]>(jsonIndex);
        Console.WriteLine($"Index populated from file @ {indexFile}");
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