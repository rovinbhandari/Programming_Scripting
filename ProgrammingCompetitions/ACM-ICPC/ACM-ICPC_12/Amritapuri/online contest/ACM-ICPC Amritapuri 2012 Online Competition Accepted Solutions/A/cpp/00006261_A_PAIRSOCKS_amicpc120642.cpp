#include<iostream>
using namespace std;
int main()
{
int t,count=0;
int s[4]={0};
cin>>t;
string st[t];
       while(t--)
       {
       cin>>st[count];
       count++;
       }
       
       t++;
       
       
       while(count--)
       {
                     s[0]=0;s[1]=0;s[2]=0;s[3]=0;
       for(int i=0;i<st[t].size();i++)
       {
               if(st[t][i]=='R')
                       s[0]=!(s[0]);
               else if(st[t][i]=='G')
                       s[1]=!(s[1]);
               else if(st[t][i]=='B')
                       s[2]=!(s[2]);
               else if(st[t][i]=='W')
                       s[3]=!(s[3]);

       }
       if(s[0]==0&&s[1]==0&&s[2]==0&&s[3]==0)
       cout<<"YES"<<endl;
       else
       cout<<"NO"<<endl;
       t++;
       }


return 0;
}
