#include <iostream> 
using namespace std;
int main()
{
    int t;
    cin>>t;
    char val[1000][50];
    int k=0;
    for (k=0;k<t;k++)
    {
        cin>>val[k];
        int r=0,g=0,b=0,w=0,c=0;
        for(c=0;val[k][c];c++)
        {
            if (val[k][c]=='R')
                r++;
            else if (val[k][c]=='G')
                g++;    
            else if (val[k][c]=='B')
                b++;    
            else if (val[k][c]=='W')
                w++;    
        }
        if(r%2==0 && g%2==0 && b%2==0 && w%2==0 )
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}