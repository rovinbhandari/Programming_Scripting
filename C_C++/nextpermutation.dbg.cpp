#include <string>
#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
using namespace std;

#define DBG false

#define INF	numeric_limits<int>::max()

void numstrtovector(string ns, vector<int>& v)
{
	v.clear();
	for(string::iterator it = ns.begin();
			it != ns.end(); it++)
		v.push_back(*it - '0');
}

int vectortonum(vector<int>& v)
{
	int n = 0;
	for(vector<int>::iterator it = v.begin();
			it != v.end(); it++)
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

void reversevector(vector<int>::iterator beg, vector<int>::iterator end)
{
	if(beg == end)
		return;
	vector<int>::iterator it1, it2;
	for(it1 = beg, it2 = end - 1; it2 - it1 > 0; it1++, it2--)
	{
		int temp = *it1;
		*it1 = *it2;
		*it2 = temp;
	}
}

bool nextpermutation(vector<int>& v)
{
	if(v.size() < 2)
		return true;
	// find the point at which the sequence (starting from the end) becomes decreasing. find the smallest element in that sequence which is just greater than the first element at which the sequence becomes decreasing. swap them and reverse the sequence.
	// if the sequence never becomes decreasing, simply return the reversed sequence.
	int min = INF, minindex;
	int i = v.size() - 1, prev = v[i], cur;
	bool founddecrseq = false;
	while(i)
	{
		cur = v[i - 1];
		if(cur < prev)
		{
			founddecrseq = true;
			break;
		}
		prev = cur;
		i--;
	}
	if(founddecrseq)
	{
		int seqstartindex = i;
		int elementtobeswappedindex = i - 1;
		while(i < v.size())
		{
			if(v[i] <= min && v[i] > v[elementtobeswappedindex])	//XXX: notice the conditions!!!
			{
				min = v[i];
				minindex = i;
			}
			i++;
		}
		
		if(DBG)
			cerr << "seqstartindex : "
				 << seqstartindex
				 << "\nelement to be swapped index : "
				 << elementtobeswappedindex
				 << "\nminindex : "
				 << minindex
				 << endl;

		int temp = v[elementtobeswappedindex];
		v[elementtobeswappedindex] = v[minindex];
		v[minindex] = temp;

		if(DBG)
			cerr << "vector post swap : ";
		if(DBG)
			printvector(v);

		if(DBG)
			cerr << "reversing between indices : "
				 << seqstartindex
				 << " and "
				 << v.size() - 1
				 << endl;

		reversevector(v.begin() + seqstartindex, v.end());
		return true;
	}
	else
	{
		reversevector(v.begin(), v.end());
		return false;	// when the next higher permutation does not exist and the first permutation is returned.
	}
}

bool useinbuilt;

int main(int argc, char* argv[])
{
	vector<int> num;
	useinbuilt = (bool) (argv[1][0] - 'f');
	while(true)
	{
		string ns;
		cin >> ns;
		if(ns.at(0) == '0' && ns.length() == 1)
			return 0;
		numstrtovector(ns, num);

		if(DBG)
			printvector(num);

		if(useinbuilt)
			next_permutation(num.begin(), num.end());
		else
			nextpermutation(num);
		
		if(DBG)
			printvector(num);

		cout << ns
			 << " --> "
			 << vectortonum(num)
			 << endl;
		
		if(DBG)
			cerr << endl;
	}
	return 0;
}
