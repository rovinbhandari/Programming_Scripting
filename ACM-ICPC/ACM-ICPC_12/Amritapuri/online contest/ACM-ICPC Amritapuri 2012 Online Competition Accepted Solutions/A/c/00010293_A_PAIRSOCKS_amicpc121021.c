#include<stdio.h>
#include<stdlib.h>
int main()
{
     int n,j,k,i,b[4]={0,0,0,0};
     char a[1000][50],c;
     scanf("%d",&n);
     for(i=0;i<n;i++)
     scanf("%s",a[i]);
     for(i=0;i<n;i++)
     {
                     for(k=0;k<4;k++)
                     b[k]=0;
                     for(j=0;a[i][j]!='\0'&&j<50;j++)
                     {

                           if(a[i][j]=='R')
                           b[0]=b[0]+1;
                           else if(a[i][j]=='B')
                           b[1]=b[1]+1;
                           else if(a[i][j]=='G')
                           b[2]=b[2]+1;
                           else if(a[i][j]=='W')
                           b[3]=b[3]+1;



                           }
      if(b[0]%2==0 && b[1]%2==0 && b[2]%2==0 && b[3]%2==0)
      printf("YES\n");
      else
      printf("NO\n");
     }
     
return 0;
 }

