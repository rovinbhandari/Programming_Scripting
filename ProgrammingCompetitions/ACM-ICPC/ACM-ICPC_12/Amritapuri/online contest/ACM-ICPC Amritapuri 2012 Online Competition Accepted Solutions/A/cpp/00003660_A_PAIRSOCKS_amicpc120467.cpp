#include <iostream>

using namespace std;

int main()
{
int t;
char c[51];

cin>>t;

while(t--)
{
    cin>>c;
    int r,g,b,w;
    r=g=b=w=0;
    for(int i=0;c[i]!='\0';i++)
    {
        if(c[i]=='R')
        {r++;
        continue;
        }
        if(c[i]=='G')
        {g++;
        continue;}
        if(c[i]=='B')
        {b++;continue;
        }
        if(c[i]=='W')
        {
            w++;continue;
        }
    }
    if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}

return 0;
}
