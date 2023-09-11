#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>
int main()
{
   int t,i,l,r,g,b,w;
   char s[51];
   scanf("%d",&t);
   while(t--)
   {
       scanf("%s",s);
       l=strlen(s);
       r=g=b=w=0;
       for(i=0;i<l;i++)
       {

           switch(s[i])
           {
               case 'R':r++;break;
               case 'G':g++;break;
               case 'B':b++;break;
               case 'W':w++;break;
           }
       }
       if(r&1||g&1||b&1||w&1)
       printf("NO\n");
       else
       printf("YES\n");
   }
   return 0;
}

