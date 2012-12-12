
#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define mod 1000000007
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef long long LL;
long long sol(int exp)
{
    if(exp==0)return 1;
    long long ans;
    ans=sol(exp/2);
    ans=(ans*ans)%mod;
    if(exp%2==1)ans=(ans*2)%mod;
    return ans;
}
int main()
{
   int n,t,k,num;
   int count;
   int flag;
   int done[20000];
   int color[20000];
   int i,j;
   int temp;
   queue<int>myqu;
   cin>>t;
   while(t--){
      cin>>n;
      vector < vector <int> > arr;
      VI emp;
      for(i=0;i<n;i++)arr.PB(emp);
      for(i=0;i<n;i++){
	 scanf("%d",&k);
	 for(j=0;j<k;j++){
	    scanf("%d",&num);
	    arr[i].PB(num);
	    arr[num].PB(i);
	 }
      }
/*      for(i=0;i<arr.size();i++){
	 for(j=0;j<arr[i].size();j++)printf("%d ",arr[i][j]);
	 printf("\n");
      }*/
      count=0;
      flag=0;
      for(i=0;i<n;i++)done[i]=0;
      for(i=0;i<n;i++)color[i]=0;
      for(i=0;i<n;i++)
      {
	 if(done[i]==0)
	 {
	     done[i]=1;
	     color[i]=0;
	     myqu.push(i);
	     count++;
	     while(!myqu.empty())
	     {
		   temp=myqu.front();
		   myqu.pop();
		   for(j=0;j<arr[temp].size();j++)
		   {
		        if(done[arr[temp][j]]==0)
			{
			   done[arr[temp][j]]=1;
			   color[arr[temp][j]]=1-color[temp];
			   myqu.push(arr[temp][j]);
			}
			else
			{
			    if(color[temp]==color[arr[temp][j]])
			    {
			          flag=1;
				  break;
			    }
			}
		   }
		   if(flag)break;
	     }
	     if(flag)break;
	 }
      }
      while(!myqu.empty())
	 myqu.pop();
      if(flag)cout<<"0"<<endl;
      else cout<<sol(count)<<endl;
   }
   return 0;
}
