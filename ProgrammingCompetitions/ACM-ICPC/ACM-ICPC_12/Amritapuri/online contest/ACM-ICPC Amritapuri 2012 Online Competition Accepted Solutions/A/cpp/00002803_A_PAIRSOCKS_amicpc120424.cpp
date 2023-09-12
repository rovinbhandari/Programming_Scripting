#include<stdio.h>
main()
{ int t,i,j,fl;
  scanf("%d",&t);
  char a[100];
  while(t--)
      { int c[4]={0};
        fl=0;
        scanf("%s",&a);
        for(i=0;a[i]!='\0';i++)
            { if(a[i]=='R')
              c[0]++;
              else if(a[i]=='G')
              c[1]++;
              else if(a[i]=='B')
              c[2]++;
              else
              c[3]++;
            }
        for(i=0;i<4;i++)
            { if(c[i]%2!=0)
              fl=1;
            }
        if(fl)
        printf("NO\n");
        else
        printf("YES\n");
      }
  return 0;
}               
