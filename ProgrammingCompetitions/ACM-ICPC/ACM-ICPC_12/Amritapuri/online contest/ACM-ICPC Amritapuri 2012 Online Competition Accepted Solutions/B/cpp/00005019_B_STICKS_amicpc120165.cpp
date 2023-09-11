#include<iostream>
#include <math.h>
#include<string.h>
using namespace std;
int main(){
long a,b,c,d;
cin>>a;
while(a--){
    cin>>b>>c;
    long st[50003];
    for(long i=0;i<b;i++){
        cin>>st[i];
        st[i]=st[i]*st[i];
    }
    long t1,t2,t3;
    long max=0;
    for(long i=0;i<c;i++){
        cin>>t1>>t2>>t3;
        if(max<t1*t1+t2*t2+t3*t3)
        max=t1*t1+t2*t2+t3*t3;
        }
    long count=0;
    for(long i=0;i<b;i++){
        if(max>=st[i])
        count++;
    }
    cout<<count<<"\n";
    }
}

