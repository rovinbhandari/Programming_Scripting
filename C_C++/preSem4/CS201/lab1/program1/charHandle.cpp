#include"charHandle.h"
#include"readFile.h"
int totalWords(ifstream f)
{
	int i, wordperline, lines = 0;
	string line = fReadline(filename, 1);
	while(i <= line.size)
	{
		if(line.at(i) == ' ')
		{
			wordperline++;
		}
	}
	while(!f.eof())
	{
		f.getline(s);
		lines++;
	}
	return (wordperline * lines);
}
void fileToArray(string *a, int *b, string line)
{



		
