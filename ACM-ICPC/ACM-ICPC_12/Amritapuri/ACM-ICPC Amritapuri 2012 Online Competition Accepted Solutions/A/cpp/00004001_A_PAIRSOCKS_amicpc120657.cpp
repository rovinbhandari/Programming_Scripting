#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{ int a,i;
  cin>>a;
  getchar();
  while(a--)
  { int num[5]={0};
    char c[51];
    gets(c);
    for(i=0;i<strlen(c);i++)
    { switch(c[i])
      { case 'R':num[0]++;
                 break;
        case 'G':num[1]++;
                 break;
        case 'B':num[2]++;
                 break;
        case 'W':num[3]++;
                 break;
      }
    } 
    for(i=0;i<4;i++)
    { if(num[i]%2!=0)
      { printf("NO\n");
	break;
      }
    }
    if(i==4)
    printf("YES\n");  
  }
  return 0;
}                   
