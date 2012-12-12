#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;
int main()
{
	int n,len,i,j;
	bool flag[4]={false,false,false,false},flagmain=true;
	char ch;
	int count[4]={0,0,0,0};
	cin>>n;
	char str[n][51];
	int val=n;
	for(j=0;j<n;j++)
	{
		cin>>str[j];
	}
	j=0;
	do
	{
		
		
		len=strlen(str[j]);
		for(i=0;i<len;i++)
		{
			
			ch=str[j][i];
			switch(ch)
			{
				
				case 'R':
					count[0]++;
					break;
				case 'G':
					count[1]++;
					break;
				case 'B':
					count[2]++;
					break;
				case 'W':
					count[3]++;
					break;
			default :exit(0);
				
			}
		}
		for(i=0;i<4;i++)
		{
			
			
			if(count[i]%2==0)
			{
				flag[i]=true;
			}
			count[i]=0;
			
		}
		
		flagmain=flag[0]&&flag[1]&&flag[2]&&flag[3];
		flag[0]=false;
	flag[1]=false;
	flag[2]=false;
	flag[3]=false;


		if(flagmain)
			{
			cout<<"YES\n";
			
			}
		else
			{
			cout<<"NO\n";
			}
	j++;
	n=val;
	}while(j<n);
	
	return 0;
}


