#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        double stick[50000];
        int N, M;
        double a, b, c, maxid=0.0;
        cin>>N>>M;
        int count=0;
        for(int j=0;j<N;j++)
        {
            cin>>stick[j];
        }
        for(int j=0;j<M;j++)
        {
            cin>>a>>b>>c;
            double id = sqrt(pow(a, 2)+pow(b, 2)+pow(c, 2));

            if(maxid<id)
            maxid = id;

         }
         for(int k=0;k<N;k++)
            {
                if(stick[k]<=maxid)
                {
                     count++;
                }
            }
         cout<<count<<"\n";
    }

    return 0;
}
