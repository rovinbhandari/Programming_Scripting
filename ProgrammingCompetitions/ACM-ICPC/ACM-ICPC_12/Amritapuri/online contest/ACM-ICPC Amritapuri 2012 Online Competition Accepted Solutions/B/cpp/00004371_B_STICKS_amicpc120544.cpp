#include<cstdio>
using namespace std;
long long l[50010];

int main()
{
 int test_cases,n,m,count,i;
 long long a,b,c,box,max;
 scanf("%d",&test_cases);
 for(int t=0;t<test_cases;t++)
 {
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)
  scanf("%lld",&l[i]);
  max=0;
  for(i=0;i<m;i++)
  {
    scanf("%lld %lld %lld",&a,&b,&c);
    box=a*a+b*b+c*c;
    if(max<box)
     max=box;
  }
  count=0;
  for(i=0;i<n;i++)
  {
    if(l[i]*l[i] <= max)
    count++;
  }
  printf("%d\n",count);
 }
}
