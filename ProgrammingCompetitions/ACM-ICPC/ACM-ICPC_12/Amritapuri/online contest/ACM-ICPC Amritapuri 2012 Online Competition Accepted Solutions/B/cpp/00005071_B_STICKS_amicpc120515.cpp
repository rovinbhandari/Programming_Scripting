#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;


int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,m;
        cin>>n>>m;
        double *arr=new double[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        sort(&arr[0],&arr[n]);
        double* box=new double[m];
        for(int i=0;i<m;i++)
        {
            int l,b,h;
            cin>>l>>b>>h;
            box[i]=sqrt(pow(h,2)+pow(l,2)+pow(b,2));
        }
        sort(&box[0],&box[m]);
        int x=n-1,y=m-1;
        int count=0;
        while(x>=0&&y>=0)
        {
            if(box[y]>arr[x])
            {
                x--;
                count++;
            }
            else if(box[y]==arr[x])
            {
                x--;y--;
                count++;
            }
            else
            {
                x--;
            }
        }
        cout<<count<<endl;

    }
}
