#include<iostream>

using namespace std;

int main()
{
	int i;
	int t;
	int r,g,b,w;
	char c[50];
	cin>>t;
	for(i=0;i<t;i++)
	{
		r=0;
		w=0;
		g=0;
		b=0;
		cin>>c;
		int j=0;
		while(c[j]!='\0')
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
			}
			j++;
		}

		if(r%2==0 && w%2 ==0 && g%2 ==0 && b%2==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}