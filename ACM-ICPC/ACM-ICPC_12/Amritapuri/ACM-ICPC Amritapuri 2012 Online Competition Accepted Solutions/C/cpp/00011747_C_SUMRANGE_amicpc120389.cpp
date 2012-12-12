#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<bitset>
#include<map>
#include<set>
#include<climits>
#include<algorithm>
#include<utility>
#include<cstdlib>
#include<cctype>
#include<queue>
#include<sstream>
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define assign(x,n) x=(int*)calloc(n,4)
#define rep(i,n) for(i=1;i<=n;++i)
#define max(a,b) ((a)>(b))?(a):(b)
typedef  long long int ull;
using namespace std;
typedef  pair<int,int> pr;



int main()
{
    
    int n,l,u,i,j,cnt,low,up,t;
    read(t);
    while(t--)
    {
                       read(n);read(l);read(u);
                      vector <int> v(n);
                      
                       
                       
                       for(i=0;i<n;i++)
                       {
                                       read(v[i]);
                       
                       }
                       sort(v.begin(),v.end());
                       cnt=0;
                       for(i=0;i<n-2;i++)
                       {
                                         if(v[i]>u)break;
                                         for(j=i+1;j<n-1;j++)
                                         {
                                                             if(v[i]+ v[j]>u)break;
                                         low=(int)(lower_bound(v.begin()+j+1,v.end(),l-v[i]-v[j])-v.begin());
                                         
                                         up=(int)(upper_bound(v.begin()+j+1,v.end(),u-v[i]-v[j])-v.begin())-1;
                                         if(low<=up)
                                         cnt+=up-low+1;
                                        // cout<<v[i]<<" "<<v[j]<<" "<<low<<" "<<up<<endl;
                                         
                                         }
                       }
                       write(cnt);
    
    }                     
                                             
                                                             
                       
                                       
                       
 //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
//getchar();
return 0;
}
