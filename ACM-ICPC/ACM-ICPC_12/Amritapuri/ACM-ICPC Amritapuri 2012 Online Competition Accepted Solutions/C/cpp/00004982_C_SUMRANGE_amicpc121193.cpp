#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test!=0){
    long long n,a,b,c,k,l,count=0,L,H;
   scanf("%lld%lld%lld",&n,&L,&H);// cin>>n>>L>>H;
    long long S[n];
    for(int i=0;i<n;i++)
    {
     scanf("%lld",&S[i]);   
    }
    sort(S,S+n);
    //for(int i =0;i<n;i++)cout<<S[i];
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
            if(S[i]+S[j]+S[k]>H) break;
            if(S[i]+S[j]+S[k]<=H && S[i]+S[j]+S[k]>=L) count++;
            }
        }
    }
    printf("%lld\n",count);//cout<<count<<endl;
    test--;
    }
    return 0;
}
