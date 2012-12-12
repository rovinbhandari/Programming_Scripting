#include <iostream>
//#include <stl>
//#inlcude <algorithm>

using namespace std;
enum {R,G,B,W};

int main()
{
    char A[52];
    int count[4];
    int T,i,j;
    cin>>T;
    for(i=0;i<T;i++)
    {
        for(j=0;j<4;j++)
        {
            count[j]=0;
        }
        cin>>A;
        for(j=0;j<52;j++)
        {
            if (A[j]=='R')
                count[R]+=1;
            else if (A[j]=='B')
                count[B]+=1;
            else if (A[j]=='G')
                count[G]+=1;
            else if (A[j]=='W')
                count[W]+=1;
            else
                break;
        }
        for(j=0;j<4;j++)
        {
            if(count[j]%2!=0)
            {
                cout<<"NO"<<endl;
                break;
            }
        }
        if(j>=4)
        {
            cout<<"YES"<<endl;
        }


    }


}
