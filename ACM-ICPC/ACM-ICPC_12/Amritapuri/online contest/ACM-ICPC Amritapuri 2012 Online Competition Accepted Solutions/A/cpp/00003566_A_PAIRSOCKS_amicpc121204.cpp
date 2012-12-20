#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int arr[26];
	char str[1000];
	int t,l,flag;
	
	cin>>t;
	while(t--)
	{
		for(int i=0;i<26;i++)
			arr[i]=0;
		flag=1;
		cin>>str;
		l=strlen(str);
		for(int i=0;i<l;i++)
			arr[(int)str[i]%65]++;

		for(int i=0;i<26;i++)
			if((arr[i]%2) != 0)
			{
				flag=0;
				break;
			}

		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	
	}
	

	return 0;
}
