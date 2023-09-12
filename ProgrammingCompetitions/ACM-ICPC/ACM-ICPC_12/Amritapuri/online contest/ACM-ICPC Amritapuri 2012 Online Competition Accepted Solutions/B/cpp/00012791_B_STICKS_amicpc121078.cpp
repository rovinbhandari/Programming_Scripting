#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    char arr[2];
    int test_cases;
    cin>>test_cases;
    int *counter=new int[test_cases];
    for(int i=0;i<test_cases;i++)
    {
        *(counter+i)=0;
        int n,m,max;
        cin>>n;
        cin>>m;
        int *l=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>*(l+j);
        }
        int *h=new int[m];
        int *b=new int[m];
        int *w=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>*(h+j);
            cin>>*(b+j);
            cin>>*(w+j);
        }
        int *d=new int[m];
        for(int    j=0;j<m;j++)
        {
            *(d+j)=(int)sqrt(pow(*(h+j),2)+pow(*(b+j),2)+pow(*(w+j),2));
        }
        max=*(d+0);
        for(int j=1;j<m;j++)
        {
            if(max<*(d+j))
                max=*(d+j);
        }
        for(int j=0;j<n;j++)
        {
            if(*(l+j)<=max)
            {
                 *(counter+i)=*(counter+i)+1;
            }
        }
        cin.getline(arr,1);
    }
    for(int i=0;i<test_cases;i++)
    {
        cout<<counter[i]<<endl;
    }
    return 0;
}