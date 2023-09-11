#include<iostream>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int red=0,green=0,black=0,white=0;
        string temp;
        cin>>temp;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='R')
            red++;
            if(temp[i]=='G')
            green++;
            if(temp[i]=='B')
            black++;
            if(temp[i]=='W')
            white++;
        }
        if(red%2==0)
        {
            if(green%2==0)
            {
                if(black%2==0)
                {
                    if(white%2==0)
                    {
                        cout<<"YES"<<endl;
                    }
                    else
                    cout<<"NO"<<endl;
                }
                else
                cout<<"NO"<<endl;
            }
            else
            cout<<"NO"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
}
