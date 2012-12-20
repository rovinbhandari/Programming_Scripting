#include<stdio.h>
#include<string.h>
int main()
{
  int t, i, len;
  scanf("%d",&t);
  for(;t>0;t--)
  {
    char str[100];
    scanf("%s",str);
    int count[4];
    len = strlen(str);
    for(i=0; i<4; i++)
      count[i]=0;
    for(i=0; i<len; i++)
    {
       if(str[i]=='R') count[0]++;
       else if(str[i]=='G') count[1]++;
       else if(str[i]=='B') count[2]++;
       else if(str[i]=='W') count[3]++;
    }
    int flag = 0;
    for(i=0; i<4; i++)
    {
       if(count[i]%2!=0)
       {
          flag = 1;
          break;
       }
    }
    if(flag==1) printf("NO\n");
    else printf("YES\n");
  }
}
