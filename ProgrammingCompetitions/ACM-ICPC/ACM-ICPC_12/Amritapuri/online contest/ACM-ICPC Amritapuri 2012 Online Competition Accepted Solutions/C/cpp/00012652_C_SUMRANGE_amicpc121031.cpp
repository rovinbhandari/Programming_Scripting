#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int N,L,H;
vector<int> Array;

int main(){
	int t,temp,sum;
	int result,low,high;
	cin>>t;
	while(t--)
	{
		result=0;
		cin>>N>>L>>H;
		Array.clear();
		for(int i=0;i<N;i++)
		{
			cin>>temp;
			if(temp>H)
				continue;
			Array.push_back(temp);
		}
		sort(Array.begin(),Array.end());
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				if(i==j)continue;
				sum=L-Array[i]-Array[j]-1;
				low=0,high=0;
				if(sum>=0)
				{
					int uper_val=int(upper_bound(Array.begin(),Array.end(),sum)-Array.begin())-j-1;
					uper_val=uper_val<0?0:uper_val;
					low=uper_val;
				}
				sum=H-Array[i]-Array[j];
				if(sum>=0)
				{
					int uper_val=int(upper_bound(Array.begin(),Array.end(),sum)-Array.begin())-j-1;
					uper_val=uper_val<0?0:uper_val;
					high=uper_val;
				}
				result+=high-low;
				
			}
		}
		cout<<result<<endl;
	}
	
	return 0;
}
