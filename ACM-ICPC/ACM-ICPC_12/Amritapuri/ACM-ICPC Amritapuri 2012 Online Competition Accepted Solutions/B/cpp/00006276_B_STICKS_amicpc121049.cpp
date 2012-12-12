#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    unsigned long long t,i,n,m,a,b,c,len,max;
    
    cin >> t;
    unsigned long long sticks[50005];
    while(t--)
    {
                cin >> n >> m;
                
                for(i=0;i<n;i++)
                                cin >> sticks[i];
                max=0;    
                for(i=0;i<m;i++)
                {
                                
                                cin >> a >> b >> c;
                                len = a*a + b*b + c*c;
                                if(len>max)
                                           max=len;
                                
                }
                unsigned long long count=0;
                for(i=0;i<n;i++)
                {
                                if(sticks[i] * sticks[i] <= max)
                                        count++;
                }
                cout << count << "\n";
                getchar();
    }

    return 0;
}
