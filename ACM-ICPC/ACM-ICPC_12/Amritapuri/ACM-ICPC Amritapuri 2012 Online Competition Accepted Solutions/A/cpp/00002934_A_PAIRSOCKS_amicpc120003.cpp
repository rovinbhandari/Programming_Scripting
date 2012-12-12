#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char arr[55];

int main()
{
    int i, t;
    int r=0, g=0, b=0, w=0;
    scanf("%d", &t);
    getchar();
    while(t--)
     {
      for(i=0;i<55;i++)
       { 
       scanf("%c", &arr[i]);
       if(arr[i] == 'R')
        r++;
       else if(arr[i] == 'G')
        g++;
       else if(arr[i] == 'B')
        b++;
       else if(arr[i] == 'W')
        w++;
       else if(arr[i] == '\n')
        break;
       }
     
     if(r % 2 == 0 && g % 2 == 0 && b % 2 == 0 && w % 2 == 0)
      printf("YES\n");
     else
      printf("NO\n");
      w = 0, r = 0, g = 0, b = 0;
    }
    return 0;
}
