#include<iostream>
#include<cstring>
using namespace std;
int main()
{
 int t,arr[4];
 cin>>t;

 while(t--)
 {
   char ch[51];
   for(int i=0;i<4;i++)
   arr[i]=0;
   
   cin>>ch;
   int l=strlen(ch);
   if(l%2!=0)  cout<<"NO"<<endl;
   else
   {
     for(int i=0;i<l;i++)
      {
         if(ch[i]=='R')
         { 
           arr[0]++;
           if(arr[0]==2)
           arr[0]=0;
         }
         if(ch[i]=='G')
         { 
           arr[1]++;
           if(arr[1]==2)
           arr[1]=0;
         }
         if(ch[i]=='B')
         { 
           arr[2]++;
           if(arr[2]==2)
           arr[2]=0;
         }
         if(ch[i]=='W')
         { 
           arr[3]++;
           if(arr[3]==2)
           arr[3]=0;
         }
      }
      int k;
      for(int i=0;i<4;i++)
      {
         if(arr[i]==0)
         k=1000;
         else{
          k=123;
          break;
          }
     }
     if(k==1000)
     cout<<"YES"<<endl;
     else
     cout<<"NO"<<endl;
 }
}

//cin>>t;

}
     
