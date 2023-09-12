#include<cstdio>
#include<cmath>
#include<utility>
#include<algorithm>

using namespace std;
int main()
{
    long int n,m,t,i;
    double arr[50001],s[50001],d[3];
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%lf",&s[i]);
        }
        for(i=0;i<m;i++)
        {
            for(int j=0;j<3;j++)
                scanf("%lf",&d[j]);
            arr[i]=sqrt((d[0]*d[0])+(d[1]*d[1])+(d[2]*d[2]));
        }
        double max=0;
        for(i=0;i<m;i++)
            if(arr[i]>max)
                max=arr[i];
        long long cntd=0,cnts=0;
        long long  sum=0;
        for(i=0;i<m;i++)
            if(arr[i]==max)
                cntd++;
        for(i=0;i<n;i++)
            if(s[i]==max)
                cnts++;
        for(i=0;i<n;i++)
        {
            if(s[i]<=max)
                sum++;
        }
      //  if((cntd*4)<cnts)
        //    sum+=(cntd*4);
        //else sum+=cnts;
        printf("%lld\n",sum);
    }
    return 0;
    }

