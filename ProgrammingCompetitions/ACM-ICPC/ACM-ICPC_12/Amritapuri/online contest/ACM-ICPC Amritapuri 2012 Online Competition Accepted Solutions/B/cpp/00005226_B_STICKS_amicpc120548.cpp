#include<iostream>
#include<vector>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
long long int m,n,i;
cin>>m>>n;
vector<long long int>a(m,0);
for(i=0;i<m;i++)
{
cin>>a[i];
a[i]=a[i]*a[i];
}
long long int l,b,h;
long long int max=0,p;
for(i=0;i<n;i++)
{
cin>>l>>b>>h;
p=l*l+b*b+h*h;
if(max<p)
max=p;
}
long long int ans=0;
                for(i=0;i<m;i++)
                        if(a[i]<=max)
                        ans++;
                        
                      cout<<ans<<endl;  
}
}
