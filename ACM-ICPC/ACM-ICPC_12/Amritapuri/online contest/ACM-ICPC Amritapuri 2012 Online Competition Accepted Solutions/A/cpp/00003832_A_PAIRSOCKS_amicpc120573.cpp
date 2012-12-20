#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<cstdio>
#include<algorithm>
#include<fstream>
using namespace std;
bool f( pair<int,int> a,  pair<int,int> b)
  {
    return (a.first<b.first)||(a.first==b.first && a.second<=b.second);
  }
int main()
{   //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,i;

    scanf("%d",&t);
        while(t--)
    {
        char str[100];
        int countr=0,countg=0,countb=0,countw=0;
        scanf("%s",str);
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='R')
               countr++;
            else if(str[i]=='G')
              countg++;
              else if(str[i]=='W')
              countw++;
              else if(str[i]=='B')
              countb++;

        }
        //cout<<countg<<countb<<countw<<countr<<endl;
        if((countr%2==0 )&& (countw%2==0)&&(countb%2==0)&&(countg%2==0))
               printf("YES\n");
                else
                printf("NO\n");
    }



    return 0;
}
