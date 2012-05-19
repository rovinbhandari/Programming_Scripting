#include<stdio.h>
#include<math.h>

int main()
{

    int n,i=0;

    scanf("%d",&n);

    while(n--)
    {
        scanf("%d",&i);
        printf("%d\n",(int)pow( 2, ceil( log( i ) / log( 2 ) ) )>>1);
    }
    return 0;
}

