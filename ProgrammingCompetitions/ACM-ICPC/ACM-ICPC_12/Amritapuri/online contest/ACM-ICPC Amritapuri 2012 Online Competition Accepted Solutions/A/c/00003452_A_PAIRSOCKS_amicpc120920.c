#include<stdio.h>
int main()
{
 int i,T,N;
 char a[100];
 int b[4];
 scanf("%d",&T);
 while(T--)
 {
  for(i=0;i<=3;i++)
   b[i]=0;
  scanf("%s",a);
  for(i=0;a[i]!='\0';i++);
  N=i;
  for(i=0;i<N;i++)
  {
   if(a[i]=='R')
   {
    if(b[0]==0)
     b[0]=1;
    else
     b[0]=0;
   }

   if(a[i]=='G')
   {
    if(b[1]==0)
     b[1]=1;
    else
     b[1]=0;
   }

   if(a[i]=='B')
   {
    if(b[2]==0)
     b[2]=1;
    else
     b[2]=0;
   }

   if(a[i]=='W')
   {
    if(b[3]==0)
     b[3]=1;
    else
     b[3]=0;
   }
  }
  int f=0;
  for(i=0;i<4;i++)
  {
   if(b[i]==1)
   {
    printf("NO\n");
    f=1;
    break;
   }
  }
  if(f==0)
   printf("YES\n");
 }
 return 0;
}
