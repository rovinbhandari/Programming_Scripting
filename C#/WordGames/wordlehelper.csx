using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

#region Constants
//const string ReposRoot = @"C:\git";
const string ReposRoot = @"R:\GitHub";
string WordListFilePath = 
    ReposRoot + @"\Programming_Scripting\C#\WordGames\EnUsTwl.txt";
string Alpha = "abcdefghijklmnopqrstuvwxyz";
int LetterCount = 5;
#endregion Constants

public IEnumerable<string> WordleWords => 
    File.ReadAllLines(WordListFilePath).Where(w => w.Length == LetterCount);

public Dictionary<char, double> FreqDistWordle =>
    FreqDist(WordleWords);

public Dictionary<char, double> FreqDistWordlePositional(int index) => 
    FreqDist(WordleWords.Select(w => w[index].ToString()));

public void PrintFreqDistWordle() => PrintFd(FreqDistWordle);

public void PrintFreqDistWordlePositional()
{
    foreach (var i in Enumerable.Range(0, LetterCount))
    {
        Console.WriteLine($"Pos {i}");
        PrintFd(FreqDistWordlePositional(i));
    }
}

public Dictionary<char, double> FreqDist(IEnumerable<string> words, bool asPct = true)
{
    var dict = new Dictionary<char, double>();
    foreach(var ch in Alpha)
        dict[ch] = 0;
    
    var wordsl = words.ToList();
    foreach (var word in wordsl)
        foreach (var ch in word)
            dict[ch] += (asPct ? (1.0 / wordsl.Count()) : 1);
    
    return dict;
}

public void PrintFd<T, U>(IDictionary<T, U> fd, bool asPct = true) where U : IComparable
{
    var list = fd.ToList();
    list.Sort((a, b) => -a.Value.CompareTo(b.Value));
    Console.WriteLine($"Count:{list.Count()}");
    foreach (var kv in list)
    {
        if (asPct)
            Console.WriteLine($"{kv.Key}\t{kv.Value, 8:p1}");
        else
            Console.WriteLine($"{kv.Key}\t{kv.Value, 8:F}");
    }
}