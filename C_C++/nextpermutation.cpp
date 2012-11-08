#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> num;

void numstrtovector(string ns)
{
	for(string::iterator it = ns.begin();
			it != ns.end(); it++)
		num.push_back(*it - '0');
}

int vectortonum()
{
	int n = 0;
	for(vector<int>::iterator it = num.begin();
			it != num.end(); it++)
		n = n * 10 + *it;
	return n;
}

void printvector(vector<int>& v)
{
	for(vector<int>::iterator it = v.begin();
			it != v.end(); it++)
		cerr << *it << " ";
	cerr << endl;
}

bool useinbuilt;

void nextpermutation(vector<int>& v)
{
	// find the point at which the sequence (starting from the end) becomes decreasing. find the smallest element in that sequence which is just greater than the first element at which the sequence becomes decreasing. swap them and reverse the sequence.
	return;
}

int main(int argc, char* argv[])
{
	useinbuilt = (bool) (argv[1][0] - 'f');
	while(true)
	{
		string ns;
		cin >> ns;
		if(ns.at(0) == '0')
			return 0;
		num.clear();
		numstrtovector(ns);
		printvector(num);
		if(useinbuilt)
			next_permutation(num.begin(), num.end());
		else
			nextpermutation(num);
		printvector(num);
		cout << ns
			 << " --> "
			 << vectortonum()
			 << endl;
	}
}
