#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#define mod 10000007
using namespace std;

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);


	int t;
	scanf("%d",&t);
	while(t--)
	{
                char str[51];
				int red=0,green=0,blue=0,white=0;
        scanf("%s",str);
        int i=0;
        while(str[i]!=NULL)
        {
            if(str[i]=='R')
            red++;
            else
            if(str[i]=='G')
            green++;
            else
            if(str[i]=='B')
            blue++;
            else
            if(str[i]=='W')
            white++;
            i++;
        }


        if((red%2==0)&&(green%2==0)&&(white%2==0)&&(blue%2==0))
        printf("YES\n");
        else
        printf("NO\n");




	}
}
