#include<iostream>
#include<algorithm>
//#include<cstdio>
using namespace std;

int main()
{ //ios::sync_with_stdio(false);

  int T,i,j,N,f,m,l,x;
  long int L,H,a[1001],count;
  long int*lbd;
  long int*ubd;

  cin>>T;

  for(i=0;i<T;i++)
  { cin>>N>>L>>H;

    for(j=0;j<N;j++)
    { cin>>a[j]; }
    
    sort(a,a+N);
    count=0;
    
    for(f=0;f<N-2;f++)
    { for(m=f+1;m<N-1;m++)
      { 
        lbd = lower_bound(a+m+1,a+N,L-a[f]-a[m]);
        ubd = upper_bound(a+m+1,a+N,H-a[f]-a[m]);
        if (lbd == a+N) break;
        if (ubd == a+m) break;
        count+=ubd-lbd;
      }
    }
    
    cout<<count<<endl;
  }
  
  return(0);
    
}
