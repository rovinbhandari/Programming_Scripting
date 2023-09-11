#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
    int num,i,j,*op,c1,c2,c3,tot;
    char str[1000][50];
    cin>>num;
    op=new int[num];
    for(i=0;i<num;i++)
    {
       cin>>str[i];
       for(j=0;str[i][j]!='\0';j++);
       tot=j;
       if(j%2)
       {
          op[i]=1;
          continue;
       }
       c1=c2=c3=0;
       for(j=0;str[i][j]!='\0';j++)
       {
          if(str[i][j]=='R')
             c1++;
          if(str[i][j]=='G')
             c2++;
          if(str[i][j]=='B')
             c3++;
          if(c1%2 || c2%2 || c3%2 || (tot-c1-c2-c3)%2)
            op[i]=1;
          else
            op[i]=0;
       }
    }
    for(i=0;i<num-1;i++)
    {
       if(op[i]==0)
          cout<<"YES\n";
       else
          cout<<"NO\n";
    }
    if(op[num-1]==0)
       cout<<"YES\n";
    else
       cout<<"NO\n";
}
