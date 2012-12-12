#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i,t,countw=0,countr=0,countg=0,countb=0,arr[1000],k,j;
	char str[100];
	cin>>t;
	if(t<=1000)
{
	for(k=0;k<t;k++)
	{
		cin>>str;
		if(strlen(str)>50)
		break;
		else
		{
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='R'||str[i]=='r')
				countr++;
			if(str[i]=='G'||str[i]=='g')
				countg++;
			if(str[i]=='W'||str[i]=='w')
				countw++;
			if(str[i]=='B'||str[i]=='b')
				countb++;
		}
		
		if((countr % 2 == 0) && (countg % 2 == 0) && (countw % 2 == 0) && (countb % 2 == 0))
			arr[k]=1;
		else
			arr[k]=0;
	
	countw=0;countr=0;countg=0;countb=0;
		}
	}
			for(j=0;j<t;j++)
			if(arr[j]==1)cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;

}

return 0;
}
