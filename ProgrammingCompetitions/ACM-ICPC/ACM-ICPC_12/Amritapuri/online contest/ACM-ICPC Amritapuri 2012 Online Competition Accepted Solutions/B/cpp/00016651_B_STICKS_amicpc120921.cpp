#include<iostream>
using namespace std;
 
long bodyDiag(long l,long b, long h)
{
    long diag=l*l+b*b+h*h;
    return diag;
}
 
 
int main()
{
       long t,i,count,l,b,h,p;
       long diag;
       cin>>t;
                for (i = 0; i < t; i++)
                {
                    int N,M;
                    count=0;
                        cin>>N>>M;
                        int k = 0;
                        long ls[50000];
                        while (k < N)
                        {
                                cin>>ls[k];
                                k++;
                        }
                        k = 0;
                        cin>>l>>b>>h;
                        diag=bodyDiag(l,b,h);
                        k++;
                        while (k < M)
                        {
                                cin>>l>>b>>h;
                                long var=bodyDiag(l,b,h);
                                if (var>diag)
                                    diag=var;
                                k++;
                        }
                        for (p = 0; p < N; p++)
                        {
                                        if (ls[p]*ls[p] <= diag)
                                        {
                                                count++;
                                        }
                        }
                        cout<<count<<endl;
                }
                return 0;
}