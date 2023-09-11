#include<iostream>
using namespace std;

int main(){
   
    int t;
   
    char ar[52];
   
    char c;
   
    int cr,cg,cb,cw, i;
   
    cin>>t;
   
    while(t--){
               cin>>ar;
              
               i = 0;
               cr = 0;
               cg = 0;
               cb = 0;
               cw = 0;
   
              
              
               while(ar[i]!='\0'){
                            if(ar[i] == 'R'){
                                     if(cr>0)
                                     cr--;
                                     else
                                     cr++;
                                     }
                           
                            else if(ar[i] == 'G'){
                                 if(cg>0)
                                 cg--;
                                 else
                                 cg++;
                                 }
                            else if(ar[i] == 'B'){
                                 if(cb>0)
                                 cb--;
                                 else
                                 cb++;
                                 }
                            else{
                                 if(cw>0)
                                 cw--;
                                 else
                                 cw++;
                                 }
                           
                     
                            i++;
                            }
                           
              
               if(cr==0 && cg==0 && cb==0 && cw==0)
               cout<<"YES"<<endl;
               else
               cout<<"NO"<<endl;
              
               }
   

    return 0;
    }