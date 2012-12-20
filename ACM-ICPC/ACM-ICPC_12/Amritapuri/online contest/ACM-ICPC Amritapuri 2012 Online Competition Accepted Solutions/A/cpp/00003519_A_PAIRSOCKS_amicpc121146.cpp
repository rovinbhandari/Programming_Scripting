#include<iostream>
using namespace std;
int main()
{

int t, a, b, c, d;
char arr[51];
cin>>t;
while(t--)
{
a=0;b=0;c=0;d=0;
cin>>arr;
for(int i=0; arr[i]!='\0'; i++)
{

if(arr[i]=='R')
{
a++;
}
else if(arr[i]=='G')
{
b++;
}
else if(arr[i]=='B')
{
c++;
}
else if(arr[i]=='W')
{
d++;
}
}
if(a%2==0 && b%2==0 && c%2==0 && d%2==0)
{
cout<<"YES"<<endl;
}
else
{

cout<<"NO"<<endl;
}
}
return 0;
}
