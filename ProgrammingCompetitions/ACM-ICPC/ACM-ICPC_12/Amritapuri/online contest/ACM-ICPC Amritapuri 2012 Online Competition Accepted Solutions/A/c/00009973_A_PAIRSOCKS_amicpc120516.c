#include<stdio.h>
#define T_MAX 1000
#define N_MAX 50

int main()
{
    int t,i,j=0,k,r=0,w=0,g=0,b=0,count=0;
    char arr[N_MAX];
    int out[T_MAX];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        j=0;
        r=0;
        w=0;
        g=0;
        b=0;
        scanf("%s",arr);
        while(arr[j]!= '\0')
        {
            if(arr[j]=='R')
            {
                r++;
            }
            if(arr[j]=='G')
            {
                g++;
            }
            if(arr[j]=='B')
            {
                b++;
            }
            if(arr[j]=='W')
            {
                w++;
            }
            j++;
        }
        if((j)%2==0)
        {
            if(r%2==0 && w%2==0 && b%2==0)
            {
                out[i]=1;
            }
            else
            {
                out[i]=0;
            }
        }
        else
        {
            out[i]=0;
        }
    }
    for(i=0;i<t;i++)
    {
        if(out[i]==0)
        {
            printf("NO");
        }
        else
        {
            printf("YES");
        }
	printf("\n");
    }
    return 0;
}
