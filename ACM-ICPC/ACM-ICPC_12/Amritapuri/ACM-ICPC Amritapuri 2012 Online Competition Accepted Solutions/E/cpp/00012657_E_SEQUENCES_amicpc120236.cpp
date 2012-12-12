using namespace std;
#include <cmath>
#include <cstdio>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
typedef long long ll; 
typedef pair<int,int> pii; 
#define FOR(i,n) for (int i = 0; i < n; i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define MP make_pair
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
#define split(str) {vs.clear();istringstream ss(str);while(ss>>(str))vs.push_back(str);}
#define PI 3.141592653589793
const int range=262144+4;	//Should be a power of 2 greater than range
const int range2=524288+10;	//Should be double of range

int arr[range2];
int beg[range2];
int end[range2];
/*
preprocess creates the entire tree
*/

void preprocess(int a,int b,int ind)
{
	beg[ind]=a;
	end[ind]=b;
	if(a!=b)
	{
		preprocess(a,(a+b)>>1,ind<<1);
		preprocess(((a+b)>>1)+1,b,(ind<<1)+1);
	}
}

int query(int x,int ind)
{
	if(x==beg[ind] && x==end[ind])
		return arr[ind];
	else if(x<=end[ind<<1])
		return query(x,ind<<1);		//Change if you need to sum from root
	else return query(x,(ind<<1)+1);	//Change if you need to sum from root
}

int query(int a,int b,int ind)
{
	if(a==beg[ind] && b==end[ind])
	{
		return arr[ind];
	}
	else if(b<=end[ind<<1])
			return query(a,b,ind<<1);  //Change if you need to sum from root
	else if(a>end[ind<<1])
		return query(a,b,(ind<<1)+1);	//Change if you need to sum from root
	else
	{	//Change if you need to sum from root
		return max(query(a,end[ind<<1],ind<<1),query(beg[(ind<<1)+1],b,(ind<<1)+1));
	}
}

void update(int a,int b,int ind,int val)
{
	if(a==beg[ind] && b==end[ind])
	{
		//Update arr[ind]
		arr[ind]=val;
		//Propagate upward if required
		for(int i=ind>>1;i>0;i=(i>>1))
			arr[i]=max(arr[i<<1],arr[(i<<1)+1]);
	}
	else if(b<=end[ind<<1])
		update(a,b,ind<<1,val);
	else if(a>end[ind<<1])
		update(a,b,(ind<<1)+1,val);
	else
	{
		update(a,end[ind<<1],ind<<1,val);
		update(beg[(ind<<1)+1],b,(ind<<1)+1,val);
	}
}
int main()
{
  int t;
  sf(t);
  while(t--)
  {
    memset(arr,0,sizeof(arr));
    memset(beg,0,sizeof(beg));
    memset(end,0,sizeof(end));
    int n;
    sf(n);
    string s;
    cin>>s;
    vector<int> zero(n+2,0);
    vector<int> ones(n+2,0);
    zero[0]=0;
    ones[0]=0;
    FOR(i,s.size())
    {
      zero[i+1]=zero[i]+((s[i]=='0')?1:0);
      
    }
    //cout<<"hello"<<endl;
    zero[s.size()+1]=zero[s.size()];
    ones[s.size()+1]=0;
    //cout<<"hello"<<endl;
    for(int i=s.size();i>0;i--)
    {
      ones[i]=ones[i+1]+((s[i-1]=='1')?1:0);
    }
    ones[0]=ones[1];
    
    preprocess(1,n,1);
    
    for(int i=1;i<=n;i++)
    {
      update(i,i,1,zero[i-1]+ones[i+1]+1);
      //cout<<zero[i-1]+ones[i+1]+1<<" dsad"<<endl;
    }
    int q;
    sf(q);
    while(q--)
    {
      int L,R;
      sf(L);sf(R);
      int val=query(L,R,1);
      val=val-zero[L-1]-ones[R+1];
      pf(val);
    }
  }
}