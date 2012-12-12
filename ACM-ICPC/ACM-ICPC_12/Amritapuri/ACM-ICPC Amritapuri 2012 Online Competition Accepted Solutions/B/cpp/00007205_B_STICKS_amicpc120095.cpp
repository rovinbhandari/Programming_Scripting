#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long long L[50000];
    long long T,i,j,N,M,max,count;
    long double tmp;
    long long s1,s2,s3;
    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>N>>M;
        for(j=0;j<N;j++)
        {
            cin>>L[j];
        }
        max=0;
        for(j=0;j<M;j++)
        {
            cin>>s1>>s2>>s3;
            //cout<<s1*s1+s2*s2+s3*s3<<endl;
            tmp=sqrt((long double)(s1*s1+s2*s2+s3*s3));
            //cout<<tmp<<endl;
            if (tmp>=max)
            {
                max = tmp;
                //cout<<max<<endl;
            }

        }
        count = 0;
        for(j=0;j<N;j++)
        {
            if(L[j] <= max)
                count++;
        }
        cout <<count<<endl;
    }


}

