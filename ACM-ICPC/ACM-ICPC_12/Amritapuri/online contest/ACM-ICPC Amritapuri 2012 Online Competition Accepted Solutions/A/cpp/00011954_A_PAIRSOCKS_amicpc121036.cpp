#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string sock;
		cin>>sock;
		int red=0,blue=0,green=0,white=0;
	
		int l=sock.size();
		for(int i=0;i<l;i++)
		{
			if(sock[i]=='R')
				red++;
			else if(sock[i]=='B')
				blue++;
			else if(sock[i]=='G')
				green++;
			else if(sock[i]=='W')
				white++;
		}
		if((red%2==0) && (white%2==0) && (blue%2==0) &&(green%2==0))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}