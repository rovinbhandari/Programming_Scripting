#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{int t;
 cin>>t;
 while(--t>=0)
 {int n,m,count=0;
   cin>>n>>m;
   int len[n];
   int box[m][3];
   for(int i=0;i<n;i++)
   cin>>len[i];
   for(int j=0;j<m;j++)
    cin>>box[j][0]>>box[j][1]>>box[j][2];
   double max=0;
   for(int j=0;j<m;j++)
   {double b=(box[j][0]*box[j][0]);
   b=b+(box[j][1]*box[j][1]);
    b=b+(box[j][2]*box[j][2]);
    b=sqrt(b);
    //cout<<b<<"b "<<endl;
   if(b>max)
    max=b;
   }
   //cout<<max;
   for(int i=0;i<n;i++)
    if(len[i]<=max)
    count++;
    cout<<count<<"\n";
 }
}
