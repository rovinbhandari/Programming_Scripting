#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int input[1003];
int solve()
{
    int ans=0;
    int n,l,h;

    cin>>n>>l>>h;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    sort(input,input+n);
    for(int i=0;i<n-2;i++)
    {
        if(input[i]>=h)
        break;
        for(int j=i+1;j<n-1;j++)
        {
            if(input[i]+input[j]>=h)
            break;
            for(int k=j+1;k<n;k++)
            {
           int sum=input[i]+input[j]+input[k];
            //cout<<sum<<endl;
            if(sum>=l && sum<=h)
            ans++;
            else if(sum>h)
            break;

    }}}
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    cout<<solve()<<endl;

}
