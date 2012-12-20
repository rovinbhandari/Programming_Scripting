#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
#define LL long long int
LL power_mod(LL a,LL n,LL m)
{
                LL MOD=m;
LL result=1;
a=a%MOD;
while(n>0)
{
if(n&1)
{
LL temp=result*a;
if(temp>MOD)
temp=temp%MOD;
result=temp;
}
n>>=1;
// n=n%MOD;
LL temp=a*a;
if(temp>MOD)
temp=temp%MOD;
a=temp;
}
return result%MOD;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int ii=0;ii<t;ii++)
    {
            int n;
            scanf("%d",&n);
            int gv=1;
            int a[n],f=0;
            for(int i=0;i<n;i++)
                a[i]=0;
            long long int co=0;
            for(int i=0;i<n;i++)
            {
                    int m;
                    scanf("%d",&m);
                    if(m==0)
                       {
                            if(a[i]==0)
                            {   a[i]=gv;
                                co++;
                                gv++;
                            }
                       }
                    for(int j=0;j<m;j++)
                    {
                    int p,q;
                    p=i;
                    scanf("%d",&q);
                    if(f==0)
                        {
                                if((a[p]==0)&&(a[q]==0))
                                {       a[p]=gv;
                                        a[q]=-1*gv;
                                        gv++;
                                     co++;
                }
                                else if(a[q]==0)
                                {       a[q]=a[p]*-1;
                                }

                                else if(a[p]==0)
                                {       a[p]=a[q]*-1;
                                }
                                else if(a[p]==a[q])
                                {       f=1;
                                        //cout<<p<<"\t"<<q<<"\n";

                }
                                else if(a[p]!=-1*a[q])
                                {       int h=a[p];
                                        int r=a[q];
                                        if(h<0)
                                               h*=-1;
                                        if(r<0)
                                                r*=-1;
                                        if(h<r)
                                        {       for(int jj=1;jj<=n;jj++)
                                                {
                                                        if(jj!=q)
                                                        {
                                                                if(a[jj]==a[q])
                                                                                a[jj]=-1*a[p];
                                                                else if(a[jj]==(-1*a[q]))
                                                                                a[jj]=a[p];
                                                        }
                                                }
                                                a[q]=-1*a[p];
                                            co--;
                    }
                                        else
                                        {
                                                for(int jj=1;jj<=n;jj++)
                                                {
                                                        if(jj!=p)
                                                        {
                                                                if(a[jj]==a[p])
                                                                                a[jj]=-1*a[q];
                                                                else if(a[jj]==(-1*a[p]))
                                                                                a[jj]=a[q];
                                                        }
                                                }
                                                a[p]=-1*a[q];
                          co--;
                                        }
                                }
                         }



                    }
            }
            if(f==1)
                   printf("0\n");
                else
                {
             // cout<<"co is "<<co <<"\n";
              long long int mo=1000000007,a=2;
                        long long int res=power_mod(a,co,mo);
             printf("%lld\n",res);
        }


    }
    return 0;
}
