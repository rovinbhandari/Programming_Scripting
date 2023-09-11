#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
  char str[100000], b[100];
   long long int t,i,ch=1;
   cin>>t;
    while(t--)
     { ch=1;
         for(i=0;i<100;i++)
          b[i]=0;

         cin>>str;
           for(i=0;str[i]!='\0';i++)
            b[str[i]]++;

            if(b[71]%2!=0)
             ch=0;
             else if(b[66]%2!=0)
             ch=0;
             else if(b[82]%2!=0)
             ch=0;
             else if(b[87]%2!=0)
             ch=0;
           if(ch)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
     }
return 0;
}
