#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{

    int t,n,i,j,r,g,b,w;
    char c[51],s[4100];
    memset ( s,0,4100 );
    cin >> t;
    for(i=0;i<t;i++)
    {
        r=g=b=w=0;
        cin >> c;
        for(j=0;j<strlen(c);j++)
        {
             if(c[j]=='R')
                r++;
             if(c[j]=='G')
                g++;
             if(c[j]=='B')
                b++;
             if(c[j]=='W')
                w++;
        }
            if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
                strcat(s,"YES\n");
            else
                strcat(s,"NO\n");
    }
    cout << s;
    return 0;
}
