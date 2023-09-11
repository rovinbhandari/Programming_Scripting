# include<iostream>
# include<stdio.h>
# include<algorithm>
# include<string.h>
# include<stdlib.h>
# include<vector>
using namespace std;
/*
struct node{
  long long int num,id;
  bool operator<(const node p)const{
  return num<p.num;
 }
 };
 */
//vector<pair<int,int> > V[10];
 // V[i].push_back(73);
 // V[a][i].first  , i.e V[a] is a set. V[a][i] is one element in it. first and second are parameters
int main()
{
         long long int t,n,i,mini,var,temp,ans,x,y,temp1,max1,z,m;
        scanf("%lld",&t);
        for(var=0;var<t;var++)
        {
                scanf("%lld %lld",&n,&m);
                long long int ar[n];
                ans = 0;
                x=0;
                y=0;
                z=0;
                temp=0;
                max1 = -1;
                for(i=0;i<n;i++)
                {
                        scanf("%lld",&ar[i]);
                }
                for(i=0;i<m;i++)
                {
                        scanf("%lld %lld %lld",&x,&y,&z);
                        temp = x*x + y*y + z*z;
                        if(temp > max1)
                        max1 = temp;
                }
                for(i=0;i<n;i++)
                {
                        if((ar[i]*ar[i])<= max1)
                        {
                                ans++;
                        } 
                }
                printf("%lld\n",ans);
 
        }
 
return 0;
}

