#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
 int n,m,test;
 vector<int> a,b,c,l;
 int i,t,stick_count,save,sum;
 long long int temp, t2;

 cin>>test;
 while(test--)
 {
  a.clear();
  b.clear();
  c.clear();
  l.clear();
  t = 0;
  stick_count = 0;
  n = 0, m = 0;
  save = 0; sum =0;
  int ma=0;
t2=0;
temp=0;
  cin>>n>>m;
 
  for(i=0;i<n;i++)
  {
   cin>>t;
   l.push_back(t);
  }
  
  for(i=0;i<m;i++)
  {
   cin>>t;
   a.push_back(t);
   cin>>t;
   b.push_back(t);
    cin>>t;
   c.push_back(t);
  }

  sum = a[0]+b[0]+c[0]; 
 
  for(i=1;i<m;i++)
  {
   if((a[i]+b[i]+c[i])>sum)
   {
    sum = a[i]+b[i]+c[i];
    save = i;
   }
  }  


  temp = a[save] * a[save] + b[save] * b[save];
  t2 = c[save] * c[save];
 temp += t2; 
 ma = (int)(sqrt(temp));
 for(i=0;i<n;i++)
   if(l[i]<= ma)
    stick_count++;
  cout<<stick_count;
 
  cout<<endl;
 } 
 return 0;
}
