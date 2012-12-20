#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() 
{
    int t;
    scanf("%d ",&t);
    for( ;t>0;t--)
    {
         int s[4]={0},flag=0;
         char a[51];
         cin.getline(a,51);
         //printf("%s",a);
         for(int i=0;a[i]!='\0';i++)
         {
                 switch(a[i])
                 {
                         case 'R':
                         s[0]=(s[0]+1)%2;
                         break;
                         case 'G':
                         s[1]=(s[1]+1)%2;
                         break;
                         case 'B':
                         s[2]=(s[2]+1)%2;
                         break;
                         case 'W':
                         s[3]=(s[3]+1)%2;
                         break;
                 }
         }
         for(int j=0;j<4;j++)
         {
                 if(s[j]!=0)
                 flag=1;
                 
         }
         if(flag==0)
         printf("YES\n");
         else 
         printf("NO\n");
    }
    //system("pause");
    return 0;

}
