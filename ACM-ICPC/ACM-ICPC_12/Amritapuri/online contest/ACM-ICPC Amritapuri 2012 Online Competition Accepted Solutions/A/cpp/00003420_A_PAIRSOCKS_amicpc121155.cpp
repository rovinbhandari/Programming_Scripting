#include<iostream>
#include <string>

using namespace std;

int main()
{
int num;
cin>>num;
string ipt;
int r=0;
int g=0;
int b=0;
int w=0;
for(int i=0;i<num;i++)
{
	cin>>ipt;
	for(int j=0;j<ipt.size();j++)
	{
		switch(ipt[j])
		{
			case 'R':
				r++;
				break;
			case 'G':
				g++;
				break;
			case 'B':
				b++;
				break;
			case 'W':
				w++;
				break;
		}
	}
	if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	r=g=b=w=0;
}
 return 0;
}
