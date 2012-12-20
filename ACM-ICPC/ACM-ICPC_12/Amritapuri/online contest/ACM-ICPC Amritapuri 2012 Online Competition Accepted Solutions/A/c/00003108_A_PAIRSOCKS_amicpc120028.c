#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
    char s[60];
    int a[100]={0};
    scanf("%s",s);
    int i=0;
    while(s[i]) {
        a[s[i]]++;
        i++;
    }
    int f=0;
    for(i=0;i<100;i++) {
        if(a[i]%2) {
            printf("NO\n");
            f=1;
            break;
        }
    }
    if(!f)printf("YES\n");
    }
    return 0;
}
