#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<map>
#include <set>
#include<vector>
using namespace std;

//#def MAX 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int count[4];
        for(int i=0;i<4;i++)
            count[i]=0;
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='R')
            {
                count[0]++;
            }
            else if(s[i]=='G')
                count[1]++;
            else if(s[i]=='W')
                count[2]++;
            else 
                count[3]++;
        }
        int flag=0;
        for(int i=0;i<4;i++)
        {
            if(count[i]%2==1)
            {
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if(!flag)
        cout<<"YES"<<endl;
    }
}
