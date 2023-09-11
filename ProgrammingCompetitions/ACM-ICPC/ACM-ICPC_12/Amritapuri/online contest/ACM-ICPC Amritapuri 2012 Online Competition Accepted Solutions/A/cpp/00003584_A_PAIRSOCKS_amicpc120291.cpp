#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int test;
	cin >> test;
//	cout << test << endl;

	while(test--)
	{
		string temp;
		vector<string> s;
		s.clear();
		cin >> temp;
//		#s.push_back(temp);
		
//		cout << temp;
//		for(int i=0;i<s.size();i++)
//		{
//			cout << s[i] << endl;
//		}
// RGBW
		
		int rc=0,bc=0,gc=0,wc=0;
		for(int i=0;i<temp.size();i++)
		{
	//		int rc=0,bc=0,gc=0,wc=0;
			if(temp[i]=='R')
			{
				rc=(rc+1)%2;
			}
			if(temp[i]=='G')
			{
				gc=(gc+1)%2;
			}
			if(temp[i]=='B')
			{
				bc=(bc+1)%2;
			}
			if(temp[i]=='W')
			{
				wc=(wc+1)%2;
			}
		}

		if ( rc==0 && bc==0 && gc==0 && wc==0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
