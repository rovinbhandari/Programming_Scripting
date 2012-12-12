#include<iostream>
#include<string>
using namespace std;

int main(int argc,char *argv[])
{
	int testcases=0;
	cin >> testcases;
	int count=0;
	for (count=0; count<testcases; count++) {
		string in;
		cin >> in;
		int out[4];
		out[0]=0;
		out[1]=0;
		out[2]=0;
		out[3]=0;
		string::iterator it;
		for (it=in.begin(); it<in.end(); it++) {
			if (*it == 'R')
				out[0]++;
			else if (*it == 'G')
				out[1]++;
			else if (*it == 'B')
				out[2]++;
			else
				out[3]++;
		}
		if (out[0]  %2 != 0){
			cout << "NO\n";
			continue;
		}
		if (out[1]  %2 != 0){
			cout << "NO\n";
			continue;
		}
		if (out[2]  %2 != 0){
			cout << "NO\n";
			continue;
		}
		if (out[3]  %2 != 0){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	return 0;
}



