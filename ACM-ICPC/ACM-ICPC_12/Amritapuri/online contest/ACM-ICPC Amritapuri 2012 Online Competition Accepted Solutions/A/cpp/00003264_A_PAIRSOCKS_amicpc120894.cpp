#include<iostream>

using namespace std;

int main()
{
    int i,R,G,B,W,test;
    char str[100];
    cin>>test;
    while(test--)
    {
        cin>>str;
        R=0;
        G=0;
        B=0;
        W=0;
        for(i=0;str[i]!='\0';i++)
           switch (str[i])
           {
               case 'R':R++;
                        break;
               case 'G':G++;
                        break;
               case 'B':B++;
                        break;
               case 'W':W++;
                        break;
               default: break;
           }
        if(R%2==0 && G%2==0 && B%2==0 && W%2==0)
           cout<<"YES"<<endl;
        else
           cout<<"NO"<<endl;
    }
    return 0;
}
