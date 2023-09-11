#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
#define gc getchar_unlocked
typedef long long int int64;
void scanint(int64 &x)
{
    register int64 c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int64 i,j,k,n,m,t,l,h,fs,sc,lb,ub,ans,sm;
vector<int64>::iterator find1,find2;
cin>>t;
while(t--)
{
cin>>n>>l>>h;
vector <int64> a;
for(i=0;i<n;i++){scanf("%lld",&k);a.push_back(k);}
sort(a.begin(),a.end());a.push_back(100000001);
ans = 0;
for(i=0;i<n-2;i++)
	{
	if(a[i]>h)break;
	for(j=i+1;j<n-1;j++)
		{
		if(a[i]+a[j]>h)break;
		sm = a[i]+a[j];
        fs = l - sm;
        sc = h - sm;
        find1 = lower_bound(a.begin()+j+1,a.end(),fs);
        find2 = upper_bound(a.begin()+j+1,a.end(),sc);  
        lb = int64(find1-a.begin());
        ub = int64(find2-a.begin());		
        ans+=ub-lb;
		}
	}
cout<<ans<<endl;
}
return 0;
}

