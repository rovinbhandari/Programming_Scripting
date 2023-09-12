#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	if(t>0 && t<=1000)
	{
		while(t>0)
		{
			string c;
			cin>>c;
			int l=c.length();
			int count1=0,count2=0,count3=0,count4=0,count5=0;
			for(int i=0;i<l;i++)
			{
				if(c.at(i)=='R'||c.at(i)=='G'||c.at(i)=='B'||c.at(i)=='W')
				{
				if(c.at(i)=='R')
				{
					count1++;
				}
				if(c.at(i)=='G')
				{
					count2++;
				}
				if(c.at(i)=='B')
				{
					count3++;
				}
				if(c.at(i)=='W')
				{
					count4++;
				}
				}
				else
				{
					count5++;
				}
			}
			if(count5==0)
			{
				if(count1%2==0 && count2%2==0 && count3%2==0 && count4%2==0)
				{
					cout<<"YES";
				}
				else
				{
					cout<<"NO";
				}
			}
				cout<<'\n';
			t--;
		}
	}
	return 0;
}
