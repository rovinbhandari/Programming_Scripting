#include "iostream"
using namespace std;
int main()
{
	char c[51];
	int r,b,g,w,t, j;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>c;
		r = b = g = w = j = 0;
		while(c[j] != '\0')
		{
			switch(c[j])
			{
				case 'R' :	++r;
							break;
				case 'B' :	++b;
							break;
				case 'G' :	++g;
							break;
				case 'W' :	++w;
							break;
			}
			++j;
		}
		if(r&1 || b&1 || g&1 || w&1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}