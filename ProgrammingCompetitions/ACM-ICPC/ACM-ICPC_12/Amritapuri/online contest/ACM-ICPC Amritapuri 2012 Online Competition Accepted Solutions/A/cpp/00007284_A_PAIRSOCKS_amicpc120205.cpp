#include <iostream>

using namespace std;

int main(){
	int test;
	cin>>test;
	while(test--)
	{
		int a[100000]={0};
		string str;
		cin>>str;
		int flag=0;
		int length=str.size();
		for(int i=0;i<length;i++)
		{		
			if(str[i]=='R'){
				a[0]++;
			}
			else if(str[i]=='G'){
				a[1]++;
			}
			else if(str[i]=='B'){
				a[2]++;
			}
			else if(str[i]=='W'){
				a[3]++;
			}
		}
		for(int j=0;j<4;j++)
		{
			if(a[j]%2!=0)
			{
				flag=1;
				cout<<"NO"<<endl;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"YES"<<endl;
		}
	}

	return 0;
}
