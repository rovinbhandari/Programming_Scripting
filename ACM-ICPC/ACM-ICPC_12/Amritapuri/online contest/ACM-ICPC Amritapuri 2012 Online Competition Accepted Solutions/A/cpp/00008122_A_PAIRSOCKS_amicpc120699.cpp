#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int N,i,j;
    int r=0,b=0,g=0,w=0;
    scanf("%d",&N);
    char C[1001][51];
    for(i=0;i<N;i++)
        scanf("%s",&C[i]);
    for(i=0;i<N;i++)
    {
        for(j=0;j<strlen(C[i]);j++)
        {
            switch(C[i][j])
            {
                case 'W':w++;break;
                case 'R':r++;break;
                case 'B':b++;break;
                case 'G':g++;break;
            }
        }
        if(((w%2))==1 || ((r%2))==1 || ((b%2))==1 || ((g%2))==1)
        {cout<<"NO"<<endl;
            //cout<<"NO"<<endl;
        }
        else
        {cout<<"YES"<<endl;
            //cout<<"YES"<<endl;
        }
        r=0;
        b=0;
        g=0;
        w=0;
    }
}
