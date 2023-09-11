#include <stdio.h>
#include <string.h>

int main()
{
    int T,i,n;
    int cr1=0,cr2=0,cr3=0,cr4=0;
    char c[51];

    scanf("%d",&T);

    while(T--)
    {
        cr1=cr2=cr3=cr4=0;
        scanf("%s",c);
        n=strlen(c);
      for(i=0;i<n;i++)
      {
         if(c[i]=='R')
         {
            cr1++;
         }
         else if(c[i]=='G')
         {
            cr2++;
         }
         else if(c[i]=='B')
         {
            cr3++;
         }
         else if(c[i]=='W')
         {
            cr4++;
         }
     }
     if(cr1%2==0 && cr2%2==0 && cr3%2==0 && cr4%2==0)
        printf("YES\n");
     else
        printf("NO\n");
 }
	return 0;
}


