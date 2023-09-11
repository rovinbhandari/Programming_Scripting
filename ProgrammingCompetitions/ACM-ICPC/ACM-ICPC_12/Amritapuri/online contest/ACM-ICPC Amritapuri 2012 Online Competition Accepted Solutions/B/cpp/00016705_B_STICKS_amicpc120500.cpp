 //#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
//#include<conio.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()


int main()
{
   int t;
   cin>>t;

   while(t-- > 0)
   {
    vector<int> a;
             int N,M;
             cin>>N>>M;
             int max=0;
             int count=0;
             for(int i=0;i<N;i++)
             {
                     int q;
                     cin>>q;
                     a.push_back(q);
             }
             for(int i=0;i<M;i++)
             {
                     int l,b,c;
                     cin>>l>>b>>c;

                     int j=(int)sqrt((long int)(l*l) + (long int)(b*b) + (long int)(c*c));
                     if(max<=j)
                     {
                                     max=(int)j;
                     }

             }
             for(int i=0;i<N;i++)
             {

                     if(a[i] <= max)
                     count++;
             }
   cout<<count<<endl;
   }



   return 0;
}
