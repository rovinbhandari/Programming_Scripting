#include<iostream>
#include<ctype.h>

using namespace std;
int main()
{
    int r,g,b,w,n,t;
    char ch;
    
    cin>>t;
    char a[t][51];
    
    if(t>=1 && t<=1000)
    {
       for(int j=0;j<t;j++)
       {cin>>a[j];}
       for(int j=0;j<t;j++)
       {r=0;
        g=0;
        b=0;
        w=0;
         for(int i=0;a[j][i]!='\0';i++)
         {  
            if(a[j][i]=='R')
            {r++;} 
            else if(a[j][i]=='G')
            {g++;}     
            else if(a[j][i]=='W')
            {w++;}
            else if(a[j][i]=='B')
            {b++;}
         }
            if(r%2==0 && g%2==0 && w%2==0 && b%2==0)
            {cout<<"YES"<<"\n";}
            else
            {cout<<"NO"<<"\n";}
            
       }      
            
       }
       
       return 0;
}      
