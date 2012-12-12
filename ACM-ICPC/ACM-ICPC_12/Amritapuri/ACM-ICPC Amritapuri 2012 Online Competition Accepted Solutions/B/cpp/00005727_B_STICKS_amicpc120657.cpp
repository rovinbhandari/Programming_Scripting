#include <iostream>

using namespace std;

int main() {
	long long t,n,m,x[100000],max,temp,l,b,h;
    cin>>t;
    char ch;
    while(t--)
    {
        cin>>n>>m;
        long long count=0;
        max=0;
        for(long long i=0;i<n;i++)
        {
            cin>>x[i];
            x[i]=x[i]*x[i];
        }
        for(long long i=0;i<m;i++)
        {
            cin>>l>>b>>h;
            temp=l*l+b*b+h*h;
            if(temp>max)
                max=temp;
        }
        for(long long i=0;i<n;i++)
        {
            if(x[i]<=max)
                count++;
        } 
        cout<<count<<endl;
        //cin>>ch;
    }
	return 0;
}