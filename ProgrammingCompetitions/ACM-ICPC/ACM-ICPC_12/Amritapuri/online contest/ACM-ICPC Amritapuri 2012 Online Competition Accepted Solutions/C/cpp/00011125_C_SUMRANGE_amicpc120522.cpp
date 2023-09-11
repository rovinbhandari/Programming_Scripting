
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<bitset>
#include<set>
#include<map>

#include<algorithm>
#include<cmath>
using namespace std;


// Definitions

#define LL long long int
#define PB push_back
#define MP make_pair
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<LL>
#define VII vector< vector<int> >
#define VLL vector< vector<LL> >
#define VP vector< PII >
#define S(a) scanf("%lld",&a)
#define St string
#define X first
#define Y second
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define GI ({int t;scanf("%d",&t); t;})

// Main Code

//LL bit[1001] = {0} ; 
void init()
{
   }
VL v(1010) ; 
//void update(int
int solve(int i , int j , LL val)
{	//if( val < 
	//cout << "X" << " " << i << " " << j << endl ;
	//system("pause") ; 
	
	int mid = (i+j)/2 ;
	//1cout << mid << endl ;
	if ( i == j  ) 
	return i ; 
	
	if( mid == i)
	{ 
	  	if ( v[mid+1] <= val ) 
		return mid+1; 
		else
		return mid ; 
		} 
	//return mid ; 
	
	//if( 
	
	if( v[mid] > val ) 
	return solve(i , mid  , val );
	
	if( v[mid] < val ) 
	return solve(mid  , j , val ) ; 
	
	if( v[mid] == val ) 
	return solve(mid , j , val ) ; 
	
   return -1;
   }

int smll(int i , int j , LL val)
{	//if( val < 
	//cout << "X" << " " << i << " " << j << endl ;
	//system("pause") ; 
	
	int mid = (i+j)/2 ;
	//1cout << mid << endl ;
	if ( i == j  ) 
	return i ; 
	
	if( mid == i)
	{ 
	  	if ( v[mid] >= val ) 
		return mid ; 
		else
		return mid+1 ; 
		} 
	//return mid ; 
	
	//if( 
	
	if( v[mid] >= val ) 
	return smll(i , mid , val );
	
	if( v[mid] < val ) 
	return smll(mid , j , val ) ; 
	
   return -1;
   }
int main()
{
       init();
       LL t;
       S(t);
       while(t--)
       {
	   	int n  ;
		LL l , h ; 
		n = GI ; 
		S(l) ; 
		S(h)  ; 
		v.clear() ; 
		for(int i = 0 ; i < n ; i++ ) 
		S(v[i]) ; 
		
		sort(v.begin() , v.begin() + n ) ; 
		LL ans = 0 ; 
		for(int i = 0 ; i < n - 2 ; i++ )
		for(int j = i + 2 ; j < n ; j++ ) 
		{ 		if( ( v[i] + v[j] + v[j-1] >= l ) && ( v[i] + v[i+1] + v[j] <= h ) )
				{
				
		  		
				
				int hi = solve(i+1,j-1,h-(v[i]+v[j]))  ;  
				
				int lo = smll(i+1,j-1,l - (v[i] + v[j] ) ) ;  
				ans += (hi-lo+1) ; 
				}
				
		}
		
		printf("%lld\n",ans) ; 
		
       }
   return 0;
}
