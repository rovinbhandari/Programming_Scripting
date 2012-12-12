#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<iterator>
using namespace std;
int main()
{
    int n;
	cin>>n;
int f1=0,f2=0,f3=0,f4=0;;
	for(int i=0;i<n;i++)
	{
		f1=0;
	f2=0;
	f3=0;
	f4=0;
		string str;
		cin>>str;
		for(int j=0;j<str.size();j++)
		{
			if(str[j]=='R')	
			   f1++;
			else if(str[j]=='G')	
			   f2++;
			else if(str[j]=='B')	
			   f3++;
			else if(str[j]=='W')	
			   f4++;
		}
	if(f1%2==0 && f2%2==0 && f3%2==0 && f4%2==0)
	cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	}

    return 0;
}
