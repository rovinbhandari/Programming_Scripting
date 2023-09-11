#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    int no_of_test, i , cR, cB, cG, cW,len;
    char ch[52];

    cin>>no_of_test;
    while(no_of_test--)
    {
        cR=0;
        cB=0;
        cG=0;
        cW=0;
        scanf("%s",ch);
        len = strlen(ch);
        for(i=0;i<len;i++)
        {
            if(ch[i]=='R')
            {
                cR++;
            }
            else if(ch[i]=='B')
            {
                cB++;
            }
            else if(ch[i]=='G')
            {
                cG++;
            }
            else if(ch[i]=='W')
            {
                cW++;
            }
        }
        if((cR%2==0) && (cG%2==0) && (cB%2==0) &&(cW%2==0))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
