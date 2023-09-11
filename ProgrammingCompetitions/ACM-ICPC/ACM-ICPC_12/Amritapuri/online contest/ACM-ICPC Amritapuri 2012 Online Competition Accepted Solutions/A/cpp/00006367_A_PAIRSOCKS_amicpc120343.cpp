#include <iostream>
#include <algorithm>
#include <vector>
#include<cstring>
using namespace std;
main () 
{
int mycount[4];
char myints[50];
int t,l;
cin>>t;
bool a[t];
int x=t,i=0;
char myints1[50];
while(x--)
{
cin>>myints;

l=strlen(myints);
vector<char> myvector (myints, myints+l);
mycount[0]= (char) count (myvector.begin(), myvector.end(),'R');
mycount[1] = (char) count (myvector.begin(), myvector.end(),'B');
mycount[2] = (char) count (myvector.begin(), myvector.end(),'G');
mycount[3] = (char) count (myvector.begin(), myvector.end(),'W');
a[i]=((mycount[0]%2==0)&&(mycount[1]%2==0)&&(mycount[2]%2==0)&&(mycount[3]%2==0));
i++;
}
for(int k=0;k<i;k++)
{
        if(a[k])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
}
}
