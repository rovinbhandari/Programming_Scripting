#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<sstream>
#include<cmath>

using namespace std;

int main()
{
 int test;
 cin>>test;
 while(test--)
 {
  map <char , int> mp;
  set <char> st;
  set <char> :: iterator it;
  string str;
  cin>>str;
  int i;
  for(i=0;i<str.size();i++)
  {
   st.insert(str[i]);
   mp[str[i]]++;
  }
  int flag=0;
  for(it=st.begin();it!=st.end();it++)
  {
   if(mp[*it] % 2 !=0)
   {
    flag=1;
    break;
   }
  }
  if(!flag)
  {
   cout<<"YES\n";
  }
  else
  {
   cout<<"NO\n";
  }
 }
  return 0;
}
