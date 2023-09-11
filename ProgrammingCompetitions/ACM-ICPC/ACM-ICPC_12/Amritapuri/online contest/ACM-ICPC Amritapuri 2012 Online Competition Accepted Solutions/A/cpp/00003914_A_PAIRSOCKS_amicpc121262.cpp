/*
 * RGBW.cpp
 *
 *  Created on: Nov 4, 2012
 *      Author: mns
 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s.length()%2 == 0)
		{
			if(count(s.begin(),s.end(),'R') %2 ==0
					&& count(s.begin(),s.end(),'G') %2 ==0
					&& count(s.begin(),s.end(),'B') %2 ==0
					&& count(s.begin(),s.end(),'W') %2 == 0)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;

		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

//2
//RGGGRG
//RGBGRW
