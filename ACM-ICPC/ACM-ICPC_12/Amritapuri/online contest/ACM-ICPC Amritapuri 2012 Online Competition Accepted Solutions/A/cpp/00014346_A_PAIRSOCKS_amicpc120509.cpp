#include <iostream>
#include <algorithm>
#include <vector>
#include<cstring>
using namespace std;
main () 
{
int mycount[4];
char myint[50];
int p,len,t;
cin>>p;
bool g[t];
int o=p,i=0;
char myints1[50];
while(o--)
{
cin>>myint;
len=strlen(myint);
vector<char> myvector (myint, myint+len);
mycount[0]= (char) count (myvector.begin(), myvector.end(),'B');
mycount[1] = (char) count (myvector.begin(), myvector.end(),'R');
mycount[2] = (char) count (myvector.begin(), myvector.end(),'W');
mycount[3] = (char) count (myvector.begin(), myvector.end(),'G');
g[i]=((mycount[0]%2==0)&&(mycount[1]%2==0)&&(mycount[2]%2==0)&&(mycount[3]%2==0));
i++;
}
for(int s=0;s<i;s++)
{
if(g[s])
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}
return 0;
}