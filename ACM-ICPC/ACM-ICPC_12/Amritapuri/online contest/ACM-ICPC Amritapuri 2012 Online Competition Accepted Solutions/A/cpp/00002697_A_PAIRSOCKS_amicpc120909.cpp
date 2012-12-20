#include<iostream>
using namespace std;
void solve()
{
    char s[100];
    cin>>s;
    int count[256]={0};
    int i=0;
    while(s[i])
    {
        count[s[i]]++;
        i++;
    }
    if((count['R']%2==0)&&(count['W']%2==0)&&(count['B']%2==0)&&(count['G']%2==0))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    solve();

}
