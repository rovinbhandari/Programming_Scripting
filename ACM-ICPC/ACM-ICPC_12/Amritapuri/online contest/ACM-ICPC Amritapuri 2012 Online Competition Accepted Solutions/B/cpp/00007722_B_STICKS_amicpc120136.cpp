#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define For(i,lb,ub) for(int i=lb;i<ub;i++)
int main()
{
  int t;
  scanf("%d",&t);
  vector<int> ans(t);
  For(i,0,t)
  {
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> sticks(n);
    double maxi=-1;
    int a,b,c;
    For(j,0,n)
      scanf("%d",&sticks[j]);
    For(j,0,m)
    {
      scanf("%d %d %d",&a,&b,&c);
      double diagonal=sqrt ((double) ( (long long )( (long long)((long long)(a)*(long long)(a)) + (long long)((long long)(c)*(long long)(c)) + (long long)((long long)(b)*(long long)(b))) ) );
      maxi=max(maxi,diagonal);
    }
    int sum=0;
    For(j,0,n)
      sum+=(sticks[j] <= maxi);
    ans[i]=sum;
  }
  For(i,0,t)
    printf("%d\n",ans[i]);
  return 0;
}
