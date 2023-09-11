#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>

#define fr(a, b, c) for(int a = b; a <= c; a++)
#define mst(a, b) memset(a, b, sizeof(a));

using namespace std;

int main()
{
    int t;
    char str[1000];;
    cin >> t;
    int a[10];
    while(t--)
    {
        cin  >> str;
        fr(i, 0, 9)
            a[i] = 0;
        for(int i = 0; str[i] != NULL; i++)
        {
            if(str[i] == 'R'){
                //cout<< "R";
                a[0]++;}
            else if (str[i] == 'G'){
                //cout << "G";
                a[1]++; }
            else if (str[i] == 'B')//{
                a[2]++;
                //cout << "B"; }
            else
                a[3]++;
        }
        /*cout << a[0] << endl;
        cout << a[1] << endl;
        cout << a[2] << endl;
        cout << a[3] << endl;*/
        if((a[0]%2==0) && (a[1]%2==0) && (a[2]%2==0) && (a[3]%2==0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
