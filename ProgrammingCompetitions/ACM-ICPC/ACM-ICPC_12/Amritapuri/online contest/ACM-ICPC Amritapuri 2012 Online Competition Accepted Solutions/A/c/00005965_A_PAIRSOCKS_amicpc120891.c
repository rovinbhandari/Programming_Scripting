#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l,z,t,len;
    char a[100];
    scanf("%d",&t);
    while(t--)
    {
        i=0;j=0;k=0;l=0;
        scanf("%s",a);
        len=strlen(a);
        for(z=0;z<len;z++)
        {
            if(a[z]=='R')
                i++;
            else if(a[z]=='G')
                j++;
            else if(a[z]=='B')
                k++;
            else if(a[z]=='W')
                l++;

        }
        if(i%2==0&&j%2==0&&k%2==0&&l%2==0)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
