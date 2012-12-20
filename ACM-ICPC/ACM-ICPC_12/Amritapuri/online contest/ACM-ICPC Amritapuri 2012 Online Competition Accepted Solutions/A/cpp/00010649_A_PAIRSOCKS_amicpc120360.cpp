#include<iostream>
#include<string.h>

using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t)
 {
                 char str[50];
                 cin>>str;
                 int aman[4]={};
                 int len=strlen(str);

                 for(int i=0;i<len;i++)
                 {if(str[i]=='R'){aman[0]=~aman[0];}
                 else if(str[i]=='G'){aman[1]=~aman[1];}
                 else if(str[i]=='B'){aman[2]=~aman[2];}
                 else {aman[3]=~aman[3];}
                 }
                 if(aman[1]==0&&aman[2]==0&&aman[3]==0&&aman[0]==0)cout<<"YES\n";
                 else cout<<"NO\n";
                 t--;

 }
 return 0;
}
