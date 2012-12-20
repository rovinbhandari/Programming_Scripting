#include <iostream>
#include <string>
using namespace std;

int main()
{
	char ch;
	long long int r=0,g=0,b=0,w=0,i=0;
	int len;
	string line;
    cin >> i;
	for(int k = 0; k < i; k++)
	{
		cin >> line;
		len = line.length();
	r = g = b = w = 0;
	for(int j = 0; j < len; j++)
	{
		ch = line[j];
		if(ch == 'R')
		r+=1;
		else if(ch == 'G')
		g+=1;
		else if(ch == 'B')
		b+=1;
		else if(ch == 'W')
		w+=1;
	}
	if((r%2 == 0) && (g%2 == 0) && (b%2 == 0) && (w%2 == 0))
	cout << "YES" << endl;
	else 
	cout << "NO" << endl;
}

return 0;
}		
