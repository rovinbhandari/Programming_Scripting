#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<string>
#include<queue>
#include<sstream>
#include<cstring>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
 
 
 
#define oo                                      (int)13e7
#define s(n)                                    scanf("%d",&n)
#define sl(n)                                   scanf("%lld",&n)
#define sf(n)                                   scanf("%lf",&n)
#define fill(a,v)                               memset(a, v, sizeof a)
#define ull                                     unsigned long long
#define ll                                              long long
#define bitcount                        __builtin_popcount
#define all(x)                          x.begin(), x.end()
#define pb( z )                                 push_back( z )
#define gcd                                     __gcd
#define FOR(m)                                  for(int i=0;i<m;i++)
#define FORS(n)                                 for(int j=0;j<n;j++)
#define REP(m,n)                                for(int i=m;i<n;i++)
#define REPS(m,n)                               for(int j=m;j<n;j++)
using namespace std;

struct box{

	int length,breadth,height;
	double d1,d2,d3,d4,d5,d6;

	box(int a,int b,int c,double d,double e,double f,double g,double h,double i){
		length=a;
		breadth=b;
		height=c;
		d1=d;
		d2=e;
		d3=f;
		d4=g;
		d5=h;
		d6=i;
	}

};


int main()
{

	int t,n,m,le,br,he;

	s(t);


	while(t--){
		s(n);s(m);

		int l[n];

		int answer=0;
		double maxi=0.0;

		vector<box> bb;

		FOR(n){
			s(l[i]);
		}

		FOR(m){

			s(le);s(br);s(he);
			double diag1=(double)sqrt(le*le+br*br);
			double diag2=(double)sqrt(br*br+he*he);
			double diag3=(double)sqrt(le*le+he*he);
			double diag4=(double)sqrt(diag1*diag1+he*he);
			double diag5=(double)sqrt(diag2*diag2+le*le);
			double diag6=(double)sqrt(diag3*diag3+br*br);
			bb.push_back(box(le,br,he,diag1,diag2,diag3,diag4,diag5,diag6));

			if(diag1>=maxi) maxi=diag1;
			if(diag2>=maxi) maxi=diag2;
			if(diag3>=maxi) maxi=diag3 ;
			if(diag4>=maxi) maxi=diag4 ;
			if(diag5>=maxi) maxi=diag5 ;
			if(diag6>=maxi) maxi=diag6 ;
			if(br>=maxi) maxi=br ;
			if(he>=maxi) maxi=he ;
			if(le>=maxi) maxi=le ;

		}

		
		FOR(n){

			if(l[i]<=maxi)	
				answer++;

		}
		
		printf("%d\n",answer);

	}



	return 0;

}
