#include<iostream>

using namespace std;

int main()
{
	int t,i,b,r,g,w;
	char str[51];
	cin>>t;
	while(t)
	{
		i=0,b=0;r=0,g=0,w=0;
		cin>>str;
		while(str[i]!='\0')
		{
			switch(str[i])
			{
				case 'R':
				case 'r':r++;
					break;
				case 'G':
				case 'g':g++;
					break;
				case 'B':
				case 'b':b++;
					break;
				case 'W':
				case 'w':w++;
					break;
					
			}
			i++;
		}
		if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
		{
			cout<<"YES"<<"\n";
		}
		else
		{
			cout<<"NO"<<"\n";
		}
		t--;
	}
					
	return 0;
}					
			
