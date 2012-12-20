//string matching and single variable just won't satisfy the condition
//using four variable and sum must be even for the yes

#include<iostream>
#include<string>

using namespace std;
int main()
{
string socks;int string_len;int soc1=0,soc2=0,soc3=0,soc4=0;
int testcases;int flag;
int sc=0;
cin >> testcases;
string s[testcases];

while(testcases--)
{
soc1=soc2=soc3=soc4=0;
cin >> socks;
string_len=socks.length();
//cout << string_len << endl;
for(int i=0;i<string_len;i++)
{
if (socks[i]=='R')
soc1++;
else if (socks[i]=='G')
soc2++;
else if (socks[i]=='B')
soc3++;
else if (socks[i]=='W')
soc4++;
}
flag=(soc1%2)+(soc2%2)+(soc3%2)+(soc4%2);
if (flag!=0)
s[sc++]="NO";
else
s[sc++]="YES";
}
for(int i=0;i<sc;i++)
{
    cout<<s[i];
    cout<<"\n";
}
return 0;
}



