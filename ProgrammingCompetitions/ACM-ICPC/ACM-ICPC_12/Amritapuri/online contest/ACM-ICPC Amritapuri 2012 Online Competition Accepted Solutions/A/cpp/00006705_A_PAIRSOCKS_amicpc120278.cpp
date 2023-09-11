#include<iostream>
using namespace std;
int main()
{
    string str;
    int i,case1,count1,count2,count3,count4;
    cin>>case1;
    while(case1--)
    {
    cin>>str;
    count1=0;
    count2=0;
    count3=0;
    count4=0;
    for(i=0;i<str.length();i++)
    {
                             if(str[i]=='R')
                             count1++;
                             else if(str[i]=='G')
                             count2++;
                             else if(str[i]=='B')
                             count3++;
                             else if(str[i]=='W')
                             count4++;
    }
    //cout<<"\n"<<count1<<count2<<count3;
    if(((count1%2)==0)&&((count2%2)==0)&&((count3%2)==0)&&((count4%2)==0))
    cout<<"YES\n";
    else
    cout<<"NO\n";
    }
    return 0;
}
