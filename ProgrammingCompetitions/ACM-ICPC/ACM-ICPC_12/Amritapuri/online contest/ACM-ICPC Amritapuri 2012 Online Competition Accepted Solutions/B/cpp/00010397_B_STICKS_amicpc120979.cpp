#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int q,t=0,x=0,s[10];
    cin>>t;
    for(q=0;q<t;q++)
    {
        long n,m,i,max=0,a,b,c;
        s[q]=0;
        cin>>n>>m;
        int *l=new int[n];
        for(i=0;i<n;i++)
        {
            cin>>l[i];
        }
        for(i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            double r=sqrt(a*a+b*b+c*c);
            if(r>max)
            {
                max=r;
            }
        }
        for(i=0;i<n;i++)
        {
            if(l[i]<=max)
                s[q]++;
        }
    }
    for(q=0;q<t;q++)
    {
        cout<<s[q]<<endl;
    }
    return 0;
}
