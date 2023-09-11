# include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
              char arr[100000];
              gets(arr);
              int n1=0,n2=0,n3=0,n4=0;
              int l=0;
              while(arr[l]!='\0')
              {
                                 if(arr[l]=='R')
                                 n1++;
                                 if(arr[l]=='G')
                                 n2++;
                                 if(arr[l]=='W')
                                 n3++;
                                 if(arr[l]=='B')
                                 n4++;
                                l++; 
              }
              if(n1%2==0&&n2%2==0&&n3%2==0&&n4%2==0)
              printf("YES\n");
              else
              printf("NO\n");
    }
}