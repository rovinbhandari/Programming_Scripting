#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
//#include <conio.h>
#include <climits>
using namespace std ;
#define REP(i,n) for ( i = 0 ; i < n ; i++ )
#define FOR(i,a,b) for ( i = (a) ; i <= (b) ; i++  )
#define SF(n) scanf("%d",&n)
#define PF(n) printf("%d\n",n)
#define TRY(n) printf ( "Hello:\t%d\n" , n )
#define MOD 1000000007

/*int binary_search ( int sticks[], int lower, int upper, int number ) {
    int mid = ( lower + upper ) / 2 ;
    if ( lower > upper )
       return -1 ;
    if ( ( number >= sticks[mid] && number < sticks[mid+1] && ( mid+1 <= upper ) ) || ( number > sticks[mid] && ( mid == upper ) ) )
       return mid ;
    if ( sticks[mid] >= number )
       return binary_search(sticks, lower, mid-1,  number) ;
    else if ( sticks[mid] < number )
       return binary_search ( sticks, mid, upper , number ) ;
}*/

/*int search (int sticks [],int low,int high,int number ) 
{
    int mid = (high+low)/2;
    if ( high - low <= 1)
    {
        if( sticks[high] <= number ) 
        return high ;
        else
        return low; 
    }
    if ( sticks[mid] == number )
    {
        return mid; 
    }
    else if ( sticks[mid] < number)
    {
        return search ( sticks, mid, high, number ) ; ;
    }
    else if ( sticks[mid] > number)
    {
        return search (sticks, low,mid - 1,number) ; 
    }   
}*/

int main ( ) {
    //freopen("B.txt","r",stdin);
    /*int a,x,c ;
    while(1) {
             cin >> a >> x >> c ;
             cout << floor ( sqrt ( a*a+x*x+c*c ) ) << endl ;
    }*/
    int t ,i ;
    int n, m ;
    int sticks[50005];
    long long l , b, h ;
    long long max ;
    long long diagnol ;
    int answer ;
    scanf("%d",&t);
    while(t--) {
         max = -INT_MAX ;
         answer = 0 ;
         scanf("%d %d",&n,&m);
         REP(i,n)
              scanf("%d",&sticks[i]);
         //sort(sticks, sticks+n);
         while(m--) {
              scanf("%lld %lld %lld",&l,&b,&h);
              diagnol = floor ( sqrt ( l*l + b*b + h*h ) ) ;
              if (diagnol > max )
                 max = diagnol ;
         }
         
         /*for ( i = 0 ; i <= n - 2 ; i++ ) {
             if ( max >= sticks[i] && max < sticks[i+1] ) {
                      printf("%d\n",i+1);
                      break ;
                }
         }
         if ( i == n - 1 && max >= sticks[i] )
            printf("%d\n",n);
         else
            printf("%d\n" , n - 1 ) ;*/
            
         for ( i = 0 ; i < n ; i++ ) {
             if ( max >= sticks[i] )
                answer++;
         }
         printf("%d\n",answer);
         
         //printf("%d\n",search(sticks,0,n-1,max));
    }
    //getch();
    return 0 ;
}
