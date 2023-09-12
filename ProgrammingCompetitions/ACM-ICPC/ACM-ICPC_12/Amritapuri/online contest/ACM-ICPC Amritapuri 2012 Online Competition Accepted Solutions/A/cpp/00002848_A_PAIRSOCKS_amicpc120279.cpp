#include<iostream>
#include<string>
#include<cstdio>


using namespace std;

int main()
{
    int r,g,w,b;
    string s;
    int t;
    scanf("%d",&t);
    int i;
    while(t--)
    {
        r=g=w=b=0;
        cin>>s;
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='R')
                r++;
            else if (s[i]=='G')
                g++;
            else if(s[i]=='W')
                w++;
            else
                b++;
        }
        if(r%2==0&&g%2==0&&w%2==0&&b%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
                
    
    
