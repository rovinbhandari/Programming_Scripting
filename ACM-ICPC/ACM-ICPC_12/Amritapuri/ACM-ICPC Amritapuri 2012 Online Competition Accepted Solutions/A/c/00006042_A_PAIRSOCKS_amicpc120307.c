#include<stdio.h>
#include<string.h>
int main()
{
  int n,i,j;
  char str[60];
  static int arr[4];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
     scanf("%s",&str);
     arr[0]=0;
     arr[1]=0;
     arr[2]=0;
     arr[3]=0;
     for(j=0;j<strlen(str);j++)
     {
         if(str[j]=='R')
         {
            arr[0]++;
         }
         if(str[j]=='G')
         {
            arr[1]++;
         }
         if(str[j]=='B')
         {
            arr[2]++;
         }
         if(str[j]=='W')
         {
            arr[3]++;
         }
     }
     if((arr[0]%2==0) && (arr[1]%2==0) && (arr[2]%2==0)&&(arr[3]%2==0) )
         printf("YES\n");
     else
        printf("NO\n");
  }
  return 0;
}
