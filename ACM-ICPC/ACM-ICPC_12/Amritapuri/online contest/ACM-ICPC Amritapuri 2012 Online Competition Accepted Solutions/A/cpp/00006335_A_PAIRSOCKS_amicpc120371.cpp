#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int t,i,n,j,flag;
    int b,r,g,w;
    cin>>t;
    vector<string> v;
    for(i=0;i<t;i++){
         b=r=g=w=0;
         string str;
         cin>>str;
         n=str.length();
         if(n%2!=0){
                  v.push_back("NO");
                  continue;
          }
         
         for(j=0;j<n;j++){
             if(str[j]=='B')
             b++;
             else if(str[j]=='R')  
             r++;
             else if(str[j]=='W')
             w++;
             else if(str[j]=='G')
             g++;  
             else{
                   v.push_back("NO");
                   flag=1;
                  break;
                  
                  }                                          
         }  
         if(flag==1){
                      flag=0;
         continue;
          
         }
        else if(b%2==0 && r%2==0 && w%2==0 && g%2==0)
            v.push_back("YES"); 
            else
            v.push_back("NO");           
                   
    } 
    for(i=0;i<v.size();i++)
    cout<<v[i]<<endl;
    cin>>t;
}
