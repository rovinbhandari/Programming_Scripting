#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int main() {
//	int r=0,g=0,b=0,w=0;
	int T;
	string yes="YES";
	string no="NO";
	int i;
	int q;
	cin >> T;
	string p[T];
	for(int q=0;q<T;q++) {
//	int i;	
int r=0,g=0,b=0,w=0;
	string str;
			cin>>str;
			for(i=0;i<str.length();i++)
			{
				if(str[i]=='R')
				{
					r++;
				}
				else if(str[i]=='G')
				{
					g++;
				}
				else if(str[i]=='B')
				{
					b++;
				}
				else if(str[i]=='W')
				{
					w++;
				}
				
			}
	if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
	{
	p[q]=yes;
	}
	else
	{
	p[q]=no;
	}
	}

for(i=0;i<T;i++)
{
cout<<p[i]<<endl;
}
	return 0;
}
