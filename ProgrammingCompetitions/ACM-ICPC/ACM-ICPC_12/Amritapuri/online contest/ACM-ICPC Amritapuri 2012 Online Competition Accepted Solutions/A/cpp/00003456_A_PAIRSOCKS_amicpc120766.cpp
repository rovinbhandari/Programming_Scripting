#include<iostream>
using namespace std;

bool checks(char a[])
{
     int count1=0,count2=0,count3=0,count4=0,i;
     
     for(i=0;a[i]!='\0';i++)
     {
         if(a[i]=='R')
         count1++;
         if(a[i]=='G')
         count2++;
         if(a[i]=='B')
         count3++;
         if(a[i]=='W')
         count4++;
     }
    
     if(((count1%2)==0)&&((count2%2)==0)&&((count3%2)==0)&&((count4%2)==0))
     { return true; }
     else
     { return false; }
}



int main()
{
    char s[50];
    int t;
    cin>>t;
    bool ans=false;
    while(t--)
    {
        cin>>s;
        ans=checks(s);
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
     
    return 0;
} 
