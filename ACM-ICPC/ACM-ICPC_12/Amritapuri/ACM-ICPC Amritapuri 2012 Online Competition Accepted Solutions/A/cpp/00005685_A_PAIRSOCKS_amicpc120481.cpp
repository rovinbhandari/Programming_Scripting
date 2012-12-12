#include<stdio.h>

int main()
{

   char A[1000][51];
   int i,j,C[4],t;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
      scanf("%s",A[i]);
   }
for(j=0;j<t;j++)
{
   C[0]=0;
   C[1]=0;
   C[2]=0;
   C[3]=0;
   for(i=0;A[j][i]!='\0';i++)
   {
      if(A[j][i]=='B')
      {
	 C[0]++;
      }
      else if(A[j][i]=='G')
      {
	 C[1]++;
      }
      else if(A[j][i]=='R')
      {
	 C[2]++;
      }
      else if(A[j][i]=='W')
      {
	  C[3]++;
      }
   }
   if(C[0]%2==0&&C[1]%2==0&&C[2]%2==0&&C[3]%2==0)
   {
      printf("YES\n");
   }
   else printf("NO\n");
}
  return 0;
}