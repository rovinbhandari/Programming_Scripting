#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#define ull unsigned long long int
#define ll long long int
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
 using namespace std;


 vector <int> a[20002];
 int b[20002],n;
 #define mod 1000000007
ll mExp(ll base,ll exp)
{

   ll res=1;
    while (exp > 0)
	{
        if ((exp& 1)== 1)
           res= (res * base)%mod;
        exp= exp>> 1;
        base = (base * base)%mod;
	}
	return res;
}

 bool chain(int index,int val)
 {
     if(b[index]==val)
       return true;
     if(b[index])
        return false;
     b[index]=val;
     val=(val%2)+1;
   //cout<<"chaining"<<index<<endl;
     bool flag=1;
     for(int i=0;i<a[index].size();i++)
          {
              if(b[a[index][i]]==b[index])
                {
                    flag=0;
                    //cout<<"cycle mili reeee\n";
                    break;
                }
               if(!chain(a[index][i],val))
                  return false;

          }
     if(!flag)
       return false;
     return true;
 }

 void bal()
 {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<a[i].size();j++)
      {
        int x=a[i][j],k;
        for(k=0;k<a[x].size();k++)
          if(a[x][k]==i)
              break;
        if(k==a[x].size())
           a[x].push_back(i);
      }
    }
 }

 int main()
 {
     int t,k,temp;
     cin>>t;
     while(t--)
     {
        cin>>n;

         for(int i=0;i<n;i++)
        {
           a[i].clear();
        }

        for(int i=0;i<n;i++)
        {
            cin>>k;
            while(k--)
            {
                cin>>temp;
                a[i].push_back(temp);
            }
        }

        bal();
        /*
        for(int i=0;i<n;i++)
         {

           cout<<i<<" ";
         for(int j=0;j<a[i].size();j++)

             cout<<a[i][j]<<" ";
           cout<<endl;
         }
          */
        for(int i=0;i<n;i++)
          b[i]=0;
        ll c=0;
        bool flag=1;
        int val;
        for(int i=0;i<n;i++)
        {
            if(b[i]==0)
            {
               //cout<<i<<"found zero\n";
               /*int j;
               for( j=0;j<a[i].size();j++)
                 if(b[a[i][j]])
                   {
                       //cout<<i<<"ka rival jo set hai "<<j<<endl;
                       break;}
               if(j==a[i].size())
               {
                  //cout<<"cki value"<<c<<endl;
                  c++;
                  val=1;
               }
               else
                  val=(b[a[i][j]]%2)+1;
               */
               c++;
               val=1;
               if(!chain(i,val))
                {
                    flag=0;
                    //cout<<"cycle at "<<i;
                    break;
                }
            }
        }
        if(flag)
        {
            //cout<<"num of chains "<<c<<endl;
            cout<<mExp(2,c)<<endl;


        }
        else
          cout<<"0\n";


        }
     return 0;
 }
