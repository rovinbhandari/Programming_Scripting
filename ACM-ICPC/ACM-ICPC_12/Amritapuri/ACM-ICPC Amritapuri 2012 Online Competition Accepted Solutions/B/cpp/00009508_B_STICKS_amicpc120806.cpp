#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
//#include<conio.h>
using namespace std;
int main()
{
    long int i,j,k[50000],t,n,m,l,le,be,he,max;
    vector<long int> v;
    vector<long int> len;
    vector<long int> b,h;
    cin>>t;
    while(t--)
    {
              long int max1=0;
              v.clear();
                            len.clear();
                                          b.clear();
                                                        h.clear();
              cin>>n>>m;
              for(i=0;i<n;i++)
              {
                              cin>>l;
                              v.push_back(l);
              }
              sort(v.begin(),v.end());
               for(i=0;i<m;i++){
                              cin>>le>>be>>he;
                              len.push_back(le);
                              b.push_back(be);
                              h.push_back(he);
              k[i]=sqrt((len[i]*len[i])+(b[i]*b[i])+(h[i]*h[i]));
              if(max1<k[i])
              max1=k[i];
              }
              max=n;
              for(j=n-1;j>=0;j--)
              {
                              if(v[j]<=max1)
                                            break;
                              
                              else
                                     max--;
              }
              cout<<max<<endl;
    }
        //       getch();
               return 0;
    }
