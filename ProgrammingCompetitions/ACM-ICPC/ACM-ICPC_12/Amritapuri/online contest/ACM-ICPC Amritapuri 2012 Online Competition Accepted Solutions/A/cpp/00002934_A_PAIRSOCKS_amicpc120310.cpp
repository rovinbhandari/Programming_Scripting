#include<stdio.h>
#include<iostream>
#include<string.h>
//#include<conio.h>
using namespace std;
main()
{
    char a[51];
    int i=0,r,g,b,w;
    int t;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%s",a);
    r=g=b=w=0;
    for(i=0;i<strlen(a);i++)
    {
        switch (a[i])
        {
            case 'R':
                r++;
                break;
                case 'G':
                    g++;
                    break;
                    case 'B':
                        b++;
                        break;
                        case 'W':
                            w++;
                        }
                    }
                        if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
                        printf("YES\n");
                        else
                        printf("NO\n");
                    } 
                      //  getch();
                    }
                        
                            
    


