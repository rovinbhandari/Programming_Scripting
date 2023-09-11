#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    int t,m,n,cnt,i;
    long long int arr[50001],maxbarr,a,b,c;
    scanf("%d",&t);
    while(t--){
               scanf("%d%d",&n,&m);
               cnt=0;
               maxbarr=0;
               for(i=0;i<n;i++){
                                scanf("%lld",&arr[i]);
               }
               for(i=0;i<m;i++){
                                scanf("%lld%lld%lld",&a,&b,&c);
                                maxbarr=max(a*a+b*b+c*c,maxbarr);
               }
               for(i=0;i<n;i++){
                                if(arr[i]*arr[i]<=maxbarr){
                                                           cnt++;
                                }
               }
               printf("%d\n",cnt);
    }
   //system("pause");
   return 0;
}
