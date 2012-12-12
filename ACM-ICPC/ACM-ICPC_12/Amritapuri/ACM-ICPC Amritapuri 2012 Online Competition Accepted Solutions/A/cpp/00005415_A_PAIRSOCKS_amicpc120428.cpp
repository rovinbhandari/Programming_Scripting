#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<char,int> A;
    int t;
    cin>>t;
    string S;
    int i,j,f;
    while(t--)
    {
        f=1;
        cin>>S;
        i=0;
        while(S[i]!='\0')
        {
            ++A[S[i]];
            i++;
        }    
    
    for(j=0;j<i;j++)
    {
        if(A[S[j]]%2!=0)
        {
            f=0;
            break;
        }
    }  
    if(f==0)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
    A.clear();
}    
}              
