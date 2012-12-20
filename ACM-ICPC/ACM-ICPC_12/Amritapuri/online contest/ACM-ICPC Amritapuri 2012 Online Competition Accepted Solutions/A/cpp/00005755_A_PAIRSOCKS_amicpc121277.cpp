#include<iostream>
#include<strings.h>
using namespace std;
main(){
       
       int t; 
       cin>>t;
       
       char out[t];
       
       for(int j=0;j<t;j++){
       
       string in;
       cin>>in;
       
       int r=0,g=0,b=0,w=0;
       
       int len = in.length();
       
       for(int i=0;i<len;i++){
               
               if(in[i]=='R') r++;
               else if(in[i]=='G') g++;
               else if(in[i]=='B') b++;
               else if(in[i]=='W') w++;
               
               }
       
       if(g%2==0&&r%2==0&&b%2==0&&w%2==0)
       out[j]='Y';
       else
       out[j]='N';
       
       }
       
       for(int j=0;j<t;j++){
               if(out[j]=='N')
               cout<<"NO\n";
               else if(out[j]=='Y')
               cout<<"YES\n";
               }
       
       //getch();
       return 0;
       
       }
