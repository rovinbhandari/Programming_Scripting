#include<iostream>
#include<algorithm>
using namespace std;
int t,i,j,n,k,l,h,arr[1000009];
int bst(int a,int b,int c)
{
    int d=(a+b)/2;
    while(a<b)
    {
        if(arr[d]>=c)
        b=d;
        else
        a=d+1;
        d=(a+b)/2;
    }
    if(arr[d]>=c)
    return d;
    else
    return 0;
}
int bst2(int a,int b,int c)
{
    int d=(a+b)/2;
    while(a<b)
    {
        if(arr[d]<=c&&a<d)
        a=d;
        else if(arr[d]<=c&&arr[d+1]<=c)
        a=d+1;
        else if(arr[d]<=c&&arr[d+1]>c)
        b=d;
        else
        b=d-1;
        d=(a+b)/2;
    }
    if(arr[d]<=c)
    return d;
    else
    return 0;
}
int main()
{
cin>>t;
while(t--)
{
    cin>>n>>l>>h;
int sum=0;
for(i=0;i<n;i++)
cin>>arr[i];
sort(arr,arr+n);
for(i=0;i<n;++i)
for(j=i+1;j<(n-1);j++)
{
int r1=bst(j+1,n-1,l-arr[i]-arr[j]);
int r2=bst2(j+1,n-1,h-arr[i]-arr[j]);
if(r1!=0&&r2!=0)
sum+=r2-r1+1;
/*cout<<i<<" "<<j<<" "<<r1<<" "<<r2<<endl;
cout<<sum<<endl;*/
}
cout<<sum<<endl;
}
return 0;
}
