#include <stdio.h>
int main()
{
    int t;
    char s[100];
    scanf("%d",&t);
    while(t--){
               scanf("%s",s);
               int i,r,b,w,g;
                r=b=g=w=0;
               for(i=0;s[i]!='\0';i++){
                                       switch(s[i]){
                                                    case 'R': r++;break;
                                                    case 'B' : b++;break;
                                                    case 'G' : g++;break;
                                                    case 'W' : w++;break;
                                       }
               }
               if((r%2==0) && (b%2==0) && (g%2==0) && (w%2==0))printf("YES\n");
               else printf("NO\n");
    }
    return 0;
}
               
