#include<iostream>
#include<map>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
#include<stack>
#include<queue>

using namespace std;

int main()
{

  int t;
  scanf("%d",&t);

  for(int tt=0;tt<t;tt++)
    {

      int n;
      int l,h;
      scanf("%d %d %d",&n,&l,&h);

      int a[n+2];

      for(int i=0;i<n;i++)
	{
	  scanf("%d",&a[i]);
	}

      sort(a,a+n);


      // do now

      int now=0;
      long long res=0;

      for(int  i=0;i<=n-3;i++)
	{
	  for(int j=i+1;j<=n-2;j++)
	    {
	      now=a[i]+a[j];

	      int s,e;
	      int c1,c2;

	      c1=l-now;
	      c2=h-now;

	      s=upper_bound(a+j+1,a+n,c1-1)-a;
	      e=upper_bound(a+j+1,a+n,c2)-a;

	      //cout<<"#"<<i<<" "<<j<<" "<<s<<" "<<e<<"\n";

	      int cool=e-s;
	      if(cool>0)
		res+=cool;

	    }
	}

      printf("%lld\n",res);


    }

  return 0;
}
