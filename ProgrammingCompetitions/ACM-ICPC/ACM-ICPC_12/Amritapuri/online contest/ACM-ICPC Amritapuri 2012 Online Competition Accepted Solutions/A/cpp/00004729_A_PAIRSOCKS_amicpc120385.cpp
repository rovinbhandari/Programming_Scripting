#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int count[4];
	int t,i,l,j;
	char str[50];
	cin>>t;
	for(j=0;j<t;j++)
	{
		cin>>str;
		l=strlen(str);
		//cout<<str<<endl;
		count[0]=0;
		count[1]=0;
		count[2]=0;
		count[3]=0;
		for(i=0;i<l;i++)
		{
			if(str[i]=='R')
			{
				count[0]++;
			
			}
			else if(str[i]=='G')
			{
				count[1]++;
			
			}
			else if(str[i]=='B')
			{
				count[2]++;
			
			}
			else if(str[i]=='W')
			{
				count[3]++;
			
			}
			else
			{
				count[0]=1;
				break;
				
			}
			
		}
		//cout<<count[0]<<"  "<<count[1]<<"  "<<count[2]<<"  "<<count[3]<<endl;
		if((count[0]%2==0)&&(count[1]%2==0)&&(count[2]%2==0)&&(count[3]%2==0))
		{
			cout<<"YES"<<endl;
			
		}
		else
		{
			cout<<"NO"<<endl;
		
		}
	}
	return 0;
}
