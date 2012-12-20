#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int M[2000000];
#define MAXIND 2000000
int N,q,a,b;
int zeros[100000];
int ones[100000];
int A[100000];

void initialize(int node, int b, int e)
  {
      if (b == e)
          M[node] = b;
      else
       {
          initialize(2 * node, b, (b + e) / 2);
          initialize(2 * node + 1, (b + e) / 2 + 1, e);
          if (A[M[2 * node]] <= A[M[2 * node + 1]])
              M[node] = M[2 * node];
          else
              M[node] = M[2 * node + 1]; 
      }
  }

int query(int node, int b, int e, int i, int j)
  {
      int p1, p2;
    

      if (i > e || j < b)
          return -1;
   int m = (b+e)/2;
   
  //compute the minimum position in the 
  //left and right part of the interval
       //cout << b << " " << e << " " << i << " " << j << endl;
      if(i == b && j == e)
      {
        return A[M[node]];
      }
      if(j <= m)
      {
        p1 = query(2 * node, b, (b + e) / 2, i, j);
                //cout<<"??1:"<<p1<<" "<<p2<<"\n";
        return p1;
      }
      if(i >= m+1)
      {
        
        p2= query(2 * node+1, m+1,e, i, j);
                //cout<<"??2:"<<p1<<" "<<p2<<"\n";
        return p2;
      }
      p1 = query(2 * node, b, (b + e) / 2, i, m);
      p2 = query(2 * node + 1, (b + e) / 2 + 1, e, m+1, j);
        //cout<<"??:"<<p1<<" "<<p2<<"\n";
    return min(p1,p2);

  }


int main(){
    int t;
    cin>>t;
    char s[100002];
    while(t--){
        scanf("%d",&N);
        scanf("%s\n",s);
        //cout<<s<<endl;
        zeros[0] = 0;
        ones[N-1] = 0;
        if(s[0]=='0') zeros[0] =1;
        if(s[N-1]=='1') ones[N-1] = 1;
        for (int i = 1; i < N; ++i)
        {
            if(s[i] == '0') zeros[i] = zeros[i-1]+1;
            else zeros[i] = zeros[i-1];
        }
        for (int i = N-2; i >=0; --i)
        {
            if(s[i] == '1') ones[i] = ones[i+1] + 1;
            else ones[i] = ones[i+1];
        }
        for (int i = 0; i < N; ++i)
        {
            A[i] = -1*(zeros[i] + ones[i]);
        }
        for (int i = 0; i < N; ++i)
        {
            //cout<<A[i]<<" ";
        }
        //cout<<endl;
        initialize(1,0,N-1);
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&a,&b);
            a--;
            b--;
            int ret = query(1,0,N-1,a,b);
            //cout<<"ret:"<<ret<<endl;
            ret = -1*ret;
            if(a==0 && b==N-1) cout<<ret<<endl;
            else if(a==0) cout<<ret-ones[b+1]<<endl;
            else if(b == (N-1)) cout<<ret-zeros[a-1]<<endl;
            else cout<<ret-zeros[a-1]-ones[b+1]<<endl;  
        }
    }
    return 0;
}
