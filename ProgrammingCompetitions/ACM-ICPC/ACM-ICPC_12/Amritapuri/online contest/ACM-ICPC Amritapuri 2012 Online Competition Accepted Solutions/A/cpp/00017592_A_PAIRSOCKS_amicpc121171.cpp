#include<iostream>
#include<string>
using namespace std;
static int count1=0,count2=0,count3=0,count4=0;
int arr[100];
int main()
{
	int T,lim=1,i;
	string s;
	cin>>T;
	while(lim<=T)
	{
	        cin>>s;
	
		for(i=0;i<s.length();i++)
		{
			if(s[i]=='R')
			  count1++;
			else if (s[i]=='B')
			  count2++;
			else if (s[i]=='G')
			  count3++;
			else
			  count4++;
	        }  
                  
		if (count1%2==0 && count2%2==0 && count3%2==0 && count4%2==0)
		{
			cout<<"YES\n";
		    count1=0;count2=0;count3=0;count4=0;
		}
		else
		{
			cout<<"NO\n";
		     count1=0;count2=0;count3=0;count4=0;
		}
		lim++;
		}
		
}
