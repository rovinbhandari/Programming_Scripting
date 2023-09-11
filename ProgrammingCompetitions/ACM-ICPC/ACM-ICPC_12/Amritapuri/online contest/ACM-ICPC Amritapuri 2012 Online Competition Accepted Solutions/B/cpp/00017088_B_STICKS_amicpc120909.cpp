#include<iostream>
#include<math.h>
using namespace std;
int solve()
{
    int n,m;
    long int a,b,c;
    long int max=0;
    long int len=0;
    int size[100003];
    long int temp;
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<n;i++)
    cin>>size[i];
    while(m--)
    {
        cin>>a>>b>>c;
        temp=(a*a)+(b*b)+(c*c);
        len=sqrt(temp);
        if(len>max){
        max=len;
        
        }
    }
    for(int i=0;i<n;i++)
    {
        
            if(size[i]<=max)
            ans++;
        
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    cout<<solve()<<endl;
}
