#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int t;
    for(scanf("%d",&t);t>0;t--)
    {
       char ch[200];
       cin>>ch;
       int len,r=0,w=0,b=0,g=0,i;       
       len=strlen(ch);
       for(i=0;i<len;i++)                            
       {
         if(ch[i]=='R')
           r++;
           
         else if(ch[i]=='G')
           g++;
         
         else if(ch[i]=='B')
           b++;
         
         else if(ch[i]=='W')
           w++;
       }    
       
       if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
         cout<<"YES\n";
         else 
         cout<<"NO\n";    
    }
  
    return 0;

}
