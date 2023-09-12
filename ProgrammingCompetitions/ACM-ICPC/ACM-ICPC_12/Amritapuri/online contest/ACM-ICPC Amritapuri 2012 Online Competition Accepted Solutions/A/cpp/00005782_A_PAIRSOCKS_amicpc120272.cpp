#include<stdio.h>
int main()
{
    int t,r,g,b,w,i;
    scanf("%d",&t);
    while(t--)
    {
                r=0;
                g=0;
                b=0;
                w=0;
                char s[100];
                scanf("%s",s);
                for(i=0;s[i]!='\0';i++)
                {
                                        switch(s[i])
                                        {
                                                    case 'R':r++;
                                                    break;
                                                    case 'G':g++;
                                                    break;
                                                    case 'B':b++;
                                                    break;
                                                    case 'W':w++;
                                                    break;
                                        }
                }
                if(b%2==0 && g%2==0 && r%2==0 && w%2==0)
                printf("YES\n");
                else
                printf("NO\n");
    
    }
    return 0;
}
