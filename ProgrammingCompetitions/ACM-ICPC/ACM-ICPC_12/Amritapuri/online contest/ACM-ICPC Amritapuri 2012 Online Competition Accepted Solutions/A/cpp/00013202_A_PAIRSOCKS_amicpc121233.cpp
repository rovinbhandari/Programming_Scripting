#include <iostream>
#include <string.h>

using namespace std;


int main()
{
	int T, r, g, b, w;
	char c[50];
	cin>>T;
	bool *flag = new bool[T];
	for (int i = 0; i < T; i++)
	{
		cin>>c;
		r = b = g = w = 0;	
		for (int j = 0; j < strlen(c); j++)
		{
			switch(c[j])
			{
				case 'R': r++; 
					  break;		
				case 'G': g++; 
					  break;
				case 'B': b++;
					  break;
				case 'W': w++;
					  break;
				default : break;
			}
		}
		if ((r % 2 == 0) && (g % 2 == 0) && (b % 2 == 0) && (w % 2 == 0))
			*(flag+i)= 1;
		else
			*(flag+i)= 0;
	}
	for (int i = 0; i < T; i++)
	{
		if (*(flag+i) == 1) 
		cout<<"YES"<<endl;
		else cout<<"NO"<<endl;		
	}
	return 0;
}
