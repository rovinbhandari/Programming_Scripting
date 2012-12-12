#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int r=0,g=0,b=0,w=0;
        cin>>s;
        
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='R')
                r++;
            else if(s[i]=='G')
                g++;
            else if(s[i]=='B')
                b++;
            else if(s[i]=='W')
                w++;
        }
        
        if(r&1 || g&1 || b&1 || w&1)
            cout<<"NO";
        else
            cout<<"YES";
        cout<<endl;
        
        
    }
    
    
    
    return 0;
}