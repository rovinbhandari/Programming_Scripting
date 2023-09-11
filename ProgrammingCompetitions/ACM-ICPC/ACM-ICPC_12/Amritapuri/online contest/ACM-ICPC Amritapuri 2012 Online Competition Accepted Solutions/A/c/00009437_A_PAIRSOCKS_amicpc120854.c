#include<stdio.h>
#include<stdlib.h>

int main(){
	int j,t;
	scanf("%d",&t);
    for(j=0;j<t;j++)
    { 
        int r=0,g=0,b=0,w=0,i;
        
        char a[51];
        scanf("%s",a);
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='R')
            r++;
            if(a[i]=='G')
            g++;
            if(a[i]=='B')
            b++;
            if(a[i]=='W')
            w++;
        }
        
        if((r%2)+(g%2)+(b%2)+(w%2)==0)
        printf("YES\n");
        else
        printf("NO\n");
    }
    
    return 0;
}
