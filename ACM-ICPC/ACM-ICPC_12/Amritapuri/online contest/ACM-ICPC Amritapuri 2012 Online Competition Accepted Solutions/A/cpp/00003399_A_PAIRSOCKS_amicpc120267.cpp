// Includes
 
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
 
// Macros
 


int main()
{
    int t,res;
	bool ok;
	string s;
	cin>>t;
	int count[4];
	while(t--)
	{
		memset(count,0,sizeof(count));
		ok = true;
		cin>>s;
		for(int i=0;i<s.length();++i)
		{
			if(s[i]=='R') ++count[0];
			else if(s[i]=='G') ++count[1];
			else if(s[i]=='B') ++count[2];
			else ++count[3];
		}
		for(int i=0;i<4;++i)
		{
			if(count[i]%2 !=0) ok=false;
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	//system("pause");
	return 0;
}
