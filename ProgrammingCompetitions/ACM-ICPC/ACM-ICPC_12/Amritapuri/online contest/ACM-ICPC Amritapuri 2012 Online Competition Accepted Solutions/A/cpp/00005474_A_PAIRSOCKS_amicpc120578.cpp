#include <iostream>
//#include <conio.h>

using namespace std;

int main()
{
   char a[55];
   int r,g,b,w;
   int rf,gf,bf,wf;
   rf=0;
   gf=0;
   bf=0;
   wf=0;
   int t;
   int n,i;
   cin>>t;
   while(t--)
   {
   cin>>a;
   rf=0;
   gf=0;
   bf=0;
   wf=0;
   for(i=0;a[i]!='\0';i++)
   {                
    if(a[i]=='R')
    {            
    if(rf==0)
             rf=1;
    else
        rf=0;
    }
    else if(a[i]=='B')
    {            
    if(bf==0)
    bf=1;
    else
    bf=0;
    }
    else if(a[i]=='G')
    {            
    if(gf==0)
    gf=1;
    else 
    gf=0;
    }
    else if(a[i]=='W')
    {            
    if(wf==0)
    wf=1;
    else
    wf=0;
    }
    else
    {
    }
    
    }
    //cout<<rf<<" "<<bf<<" "<<gf<<" "<<wf;
  
    if((rf==0)&&(bf==0)&&(gf==0)&&(wf==0))
    {
                         cout<<"YES\n";
                         
    }
    else
    {
        cout<<"NO\n";
    
    }
   rf=0;
   gf=0;
   bf=0;
   wf=0;
}
                         
                                 
   
   
  // getch();
   
   return 0;
}
  
