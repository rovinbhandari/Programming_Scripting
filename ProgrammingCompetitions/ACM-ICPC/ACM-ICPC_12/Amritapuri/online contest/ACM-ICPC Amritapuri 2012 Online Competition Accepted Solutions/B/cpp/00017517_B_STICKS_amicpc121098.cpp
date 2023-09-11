#include<iostream>
#include<math.h>
using namespace std;
int main()
{
 int T1;
 cin>>T1;
 int v[T1];
 for(int a=0;a<T1;a++)
  {
   if(T1>=1&&T1<=10)
   {
    int N,M;
    cin>>N>>M;
    int s[N];
    long int l,b,h;
    double d[M];
    for(int i=0;i<N;i++)
     {cin>>s[i];}
    for(int j=0;j<M;j++)
       {cin>>l>>b>>h;
         d[j]=sqrt(pow(l,2)+pow(b,2)+pow(h,2));

       }
     double big=d[0];
     for(int c=1;c<M;c++)
      {
         if(d[c]>big)
           {
             big=d[c];
           }
      }

     int count=0;
     for(int k=0;k<N;k++)
       {
        if(s[k]<=big)
           count++;
        }
     v[a]=count;
    }
   }
 for(int e=0;e<T1;e++)
   cout<<v[e]<<endl;
return 0;
}
