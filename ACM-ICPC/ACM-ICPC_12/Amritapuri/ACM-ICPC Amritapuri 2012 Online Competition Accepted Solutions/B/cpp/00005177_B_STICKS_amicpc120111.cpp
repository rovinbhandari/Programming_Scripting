#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int TestCases;
    cin>>TestCases;
    for(int i = 0;i<TestCases;i++)
    {
        double val = 0.0;
        int sticks;
        int boxes;
        int ans = 0;
        cin>>sticks>>boxes;
        int* aSticks;
        aSticks = new int[sticks];
        for(int j =0;j<sticks;j++)
        {
            cin>>aSticks[j];
        }
        for(int k =0;k<boxes;k++)
        {
            int l,b,h;
            cin>>l>>b>>h;
            double diag = sqrt(pow(l,2)+pow(b,2)+pow(h,2));
            if(diag > val) val = diag;
        }
        for(int j =0;j<sticks;j++)
        {
            if(aSticks[j] <= (int)val) ans++;
        }
        cout<<ans<<endl;
        cin.get();
    }
}
