#include <iostream>

using namespace std;

int main() 
{
    string s;
    int t;
    cin>>t;
    while(t--)
    {
    int a[]={0,0,0,0};
    cin>>s;
    for(int i=0;i<s.length();i++)
        {
            if(s[i]=='R')
                a[0]++;
            else if(s[i]=='G')
                a[1]++;
            else if(s[i]=='B')
                a[2]++;
            else if(s[i]=='W')
                a[3]++;
        }
    if((a[0]%2==0)&&(a[1]%2==0)&&(a[2]%2==0)&&(a[3]%2==0))
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
    }
	return 0;
}