#include <iostream>

using namespace std;

int main()
{
    char c[1000][50];
    int n, t[1000][4] = {0};
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>c[i];
        for(int j = 0; j < sizeof(c[i]); j++)
        {
            switch(c[i][j])
            {
                case 'R':
                    t[i][0]++;
                    break;
                case 'G':
                    t[i][1]++;
                    break;
                case 'B':
                    t[i][2]++;
                    break;
                case 'W':
                    t[i][3]++;
                    break;

             }
        }
    }
    for(int i = 0; i < (n-1); i++)
    {
            if((t[i][0]%2 == 0) && (t[i][1]%2 == 0) && (t[i][2]%2 == 0) && (t[i][3]%2 == 0))
                cout<<"YES";
            else
                cout<<"NO";
            cout<<endl;
    }
    if((t[n-1][0]%2 == 0) && (t[n-1][1]%2 == 0) && (t[n-1][2]%2 == 0) && (t[n-1][3]%2 == 0))
                cout<<"YES";
        else
                cout<<"NO";
    cout<<endl;
}
