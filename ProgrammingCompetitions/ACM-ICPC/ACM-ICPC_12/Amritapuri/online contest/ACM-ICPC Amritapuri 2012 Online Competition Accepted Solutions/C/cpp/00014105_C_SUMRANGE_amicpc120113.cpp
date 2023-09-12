//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
//some common functionn
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define FORs(i,a,b)             for(int i=a;i>=b;i--)
#define fill(a,v)               memset(a,v,sizeof a)
#define abS(x)                  ((x)<0?-(x):(x))
#define mP                      make_pair
#define pB                      push_back
#define error(x)                cout << #x << " : " << (x) << endl
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Output macros
#define p(n)                        printf("%d",n)
#define pc(n)                       printf("%c",n)
#define pl(n)                       printf("%lld",n)
#define pf(n)                       printf("%lf",n)
#define ps(n)                       printf("%s",n)

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;

using namespace std;

void chekarre(int * arr,int n)
{
    cout<<"[";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"]"<<endl;
}





int main()
    {   int n,m,l,o,chek=0;
        cin>>n;int q=0;
        while(q<n)
        {

		cin>>m>>l>>o;
        int p=0,A[1005]={0};
        while(p<m)
        {
            cin>>A[p];p++;
        }
        sort(A,A+p);
		int count=0;
		int j,k,jack;
		//chekarre(A,p);
        for (int i=0;i<m-2;i++)
		{
     
		  j=i+1;
		  k=m-1;
		  chek=0;
		  while(k>j)
		  {
		        if(A[i]+A[j]+A[k]>=l && A[i]+A[j]+A[k]<=o )
        		{
        		//	cout<<endl;
        		//	error(i);error(j);error(k);
		            //count++;
		            //k--;
					jack=k;
		            while(k>j)
					  {
					  	
						  if(A[i]+A[j]+A[k]>=l && A[i]+A[j]+A[k]<=o)
                               {
							   count++;
							   //error(i);error(j);error(k);
							   }
						   else
							break;
						k--;
					  }
		           
		            j++;
					//error(j);
				
					k=jack;
				
				}
		        else
		        {
					 k--;
		        }
		 }
        }
       
             q++;
			 cout<<count<<endl;
        }
        return 0;
}










