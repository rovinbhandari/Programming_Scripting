#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i,j,k,T,N,t;
    bool output[1000];
    char x,r = 'R',g='G',b='B',w='W';
    unsigned int bucket[4];
    for(i=0; i<4;i++)
    {
        bucket[i]=0;
    }
    cin>>T;
    t = T;

    while(T>=0)
    {
        scanf("%c",&x);
        while(x != '\n')
        {
            if(x == r) bucket[0]++;
            if(x ==g) bucket[1]++;
            if(x==b) bucket[2]++;
            if(x==w) bucket[3]++;
            //cout<<x;
            scanf("%c",&x);


        }
        //cout<<endl;
        if( bucket[0]%2 == 0 && bucket[1]%2 == 0 && bucket[2]%2 == 0 && bucket[3]%2 == 0)
            output[T] = true;
        else output[T] = false;
        T--;

        for(i=0; i<4;i++)
        {
            bucket[i]=0;
        }
    }

    for(i =t-1;i>=0;i--)
    {
        if(output[i])
            printf("YES\n");
        else printf("NO\n");

    }

    return 0;
}
