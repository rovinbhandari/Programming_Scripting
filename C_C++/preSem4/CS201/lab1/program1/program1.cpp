#include"readFile.h"
#include"charHandle.h"
#include"wordSort.h"
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	cout<<"Enter the name of the file to operate upon : \n";
	string filename;
	getline(cin, filename);
	ifstream f;
	f = fOpen(filename);
	int wordcount = totalWords(f);
	string words [wordcount];
	int freqs [wordcount];
	int line = 0;
	while(!f.eof())
	{
		fileToArray(words, freqs, fReadline(f, line));
		line++;
	}
