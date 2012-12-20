#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> a;

int main()
{
	int t, n, l, h;
	cin>>t;
	for( int cas = 1; cas <= t; cas++)
	{
		cin>>n>>l>>h;
		for( int i = 0; i < n; i++)
		{
			int temp;
			cin>>temp;
			a.push_back(temp);	
		}
		sort( a.begin(), a.end());
		int sol = 0;
		for( int i = 0; i < n-2; i++)
		{
			for( int j = i+1; j < n-1; j++)
			{
				if( a[i] + a[j] > h)
					break;
				int temp;
				temp = l-(a[i]+a[j]);
				vector<int>::iterator it1 = lower_bound( a.begin()+j+1, a.end(), temp);
				temp = h-(a[i]+a[j]);
				vector<int>::iterator it2 = upper_bound( a.begin()+j+1, a.end(), temp);
				if( it2-it1 > 0)
					sol += it2-it1;
			}
		}
		a.clear();
		cout<<sol<<endl;
	}
}

