#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{

    int n,r,g,b,w;

    scanf("%i",&n);

    string s;

    while(n)
    {
        r=g=b=w=0;
        cin>>s;

        for(int i=0;s[i]!='\0';++i)
        {
            switch(s[i])
            {
                case 'r':
                case 'R': r=(r==1)?0:1;  break;
                case 'g':
                case 'G': g=(g==1)?0:1;  break;
                case 'b':
                case 'B': b=(b==1)?0:1;  break;
                case 'w':
                case 'W': w=(w==1)?0:1;  break;
            }
        }

        if(r||g||b||w)
           printf("NO\n");
        else
           printf("YES\n");

        n--;
    }

return 0;
}
