#include<iostream>
using namespace std;

int main()
{
    int i,n,j,a=0,b=0,c=0,d=0;
    char str[60];
    cin >> n;
    for(i=0;i<n;i++)
    {
	a=0;b=0;
	c=0;d=0;
        cin >> str;
        for(j=0;str[j]!='\0';j++)
            {
                if(str[j]=='W')
                    a=!a;
                if(str[j]=='R')
                    b=!b;
                if(str[j]=='G')
                    c=!c;
                if(str[j]=='B')
                    d=!d;
            }
        if(a+b+c+d)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}