#include <iostream>

using namespace std;

int main()
{
    bool R=true,G=true,B=true,W=true;
    int j=0,testCase;
    string inputString[1000];
    cin>>testCase;
    while(j<testCase)
    {

        cin>>inputString[j];
        j++;
    }
    j=0;
    while(j<testCase){
        R=true,G=true,B=true,W=true;
        for(int i=0;i<inputString[j].length();i++)
        {
            if(inputString[j][i]=='R')
            {
                R=!R;
            }
            else if(inputString[j][i]=='G')
            {
                G=!G;

            }
            else if(inputString[j][i]=='B')
            {
                B=!B;

            }
            else if(inputString[j][i]=='W')
            {
                W=!W;
            }
        }
        if(B&&G&&W&&R)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        j++;
    }
    return 0;
}
