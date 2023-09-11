#include<stdio.h>
#include<string.h>
main()
{
      char a[51];
      int r,g,w,b,i;
      int t;
      scanf("%d",&t);
      while(t--)
      {
                scanf("%s",a);
                r=0;g=0;b=0;w=0;
                for(i=0;i<strlen(a);i++)
                { if(a[i]=='R')
                r++;
                if(a[i]=='G')
                g++;
                if(a[i]=='B')
                b++;
                if(a[i]=='W')
                w++;}
                if(r%2==0&&g%2==0&&w%2==0&&b%2==0)
                printf("YES\n");
                else
                printf("NO\n");
                }
                return 0;
                }
