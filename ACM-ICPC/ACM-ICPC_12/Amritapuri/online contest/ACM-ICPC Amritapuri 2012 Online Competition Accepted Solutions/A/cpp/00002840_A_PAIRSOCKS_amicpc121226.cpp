#include<iostream>
using namespace std;
int main()
{
    char str[60];
    int tc,i,count1,count2,count3,count4;
    cin>>tc;
    while(tc--)
    {
       count1=0;
       count2=0;
       count3=0;
       count4=0;
       cin>>str;
       for(i=0;str[i]!='\0';i++)
       {
           if(str[i]=='R')
           count1++;
           
           if(str[i]=='B')
           count2++;
           
           if(str[i]=='W')
           count3++;
           
           if(str[i]=='G')
           count4++;
           
       }
       
       if(count1%2==0 && count2%2==0 && count3%2==0 && count4%2==0)
          cout<<"YES\n";
          
       else
       cout<<"NO\n";
    }
    return 0;
}
