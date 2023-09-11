#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v,vres;
int findtrip(int l,int h)
{
	if(v.size() <3)
	return 0;

	sort(v.begin(),v.end());
	int len=v.size();
	if((v[len-1]+v[len-2]+v[len-3])<l || (v[0]+v[1]+v[2]) >h)
	return 0;

	int count=0;
	for(int i=0;i<len-2;i++)
	{
		int l1=l-v[i],h1=h-v[i];
		int j=i+1,k=len-1;
		if((v[k-1]+v[k])<l1)
		continue;
		if((v[j]+v[j+1])>h1)
		continue;
		int jorig=-1;
		while(k>j)
		{
			int sum=v[j]+v[k];
			if(sum>h1)
			{
				k--;
				continue;
			}
			if(sum<l1)
			{
				j++;
				continue;
			}
			if(jorig==-1)
			jorig=j;
			else
			{
				int t1=jorig;
				jorig=j;
				j=t1;
			}
			sum=v[j]+v[k];
			while(j<k && sum>=l1 && sum<=h1)
			{
				j++;
				if(j==k)
				break;
				sum=v[j]+v[k];
			}
			count=count+(j-jorig);
			k--;
			int t=jorig;
			jorig=j;
			j=t;			
			if(jorig==(k+1))
			jorig=k;
		}
	}
	return count;
}
int main()
{
	int t;
	cin>>t;
	int n,l,h;
	vres=vector<int>(t);
	for(int j=0;j<t;j++)
	{
		cin>>n;
		cin>>l;
		cin>>h;
		v.clear();
		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			v.push_back(k);
		}
		vres[j]=findtrip(l,h);	
	}	
	for(int i=0;i<t;i++)
	{
		cout<<vres[i]<<"\n";		
	}
}