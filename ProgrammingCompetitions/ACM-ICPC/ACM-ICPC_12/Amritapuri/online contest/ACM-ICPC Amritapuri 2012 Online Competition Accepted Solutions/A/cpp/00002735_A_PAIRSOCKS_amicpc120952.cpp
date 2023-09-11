#include<cstdio>
#include<cstring>


using namespace std;
int main()
{
    int t,i;
    char a[55];
    int r,g,b,w;
    scanf("%d",&t);
    while(t--)
    {
        r=0;
        g=0;
        b=0;
        w=0;
        scanf("%s",&a);
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='R')
                r++;
            else if(a[i]=='G')
                g++;
            else if(a[i]=='B')
                b++;
            else if(a[i]=='W')
                w++;

        }
         if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
                printf("YES\n");
            else
                printf("NO\n");

    }

    return 0;
}
