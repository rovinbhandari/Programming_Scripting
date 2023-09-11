#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std ;

int l[50005] ;

int main ()
{
    int test ;
    scanf ( "%d" , &test ) ;
    while ( test -- )
    {
    int n , m ;
    scanf ( "%d %d" , &n , &m ) ;
    
    int i ;
    for ( i = 0 ; i < n ; i ++ )
    {
        scanf ( "%d" , &l[i] ) ;
    }
    
    double length;
    double maxlen = 0 ;
    long long int x , y , z ;
    for ( i = 0 ; i < m ; i ++ )
    {
        scanf ( "%lld %lld %lld" , &x , &y , &z ) ;
        length = sqrt ( x*x + y*y + z*z ) ;        
        if ( length > maxlen )
        {
             maxlen = length ;
        }
    }
    
    int count = 0 ;
    
    for ( i = 0 ; i < n ; i ++ )
    {
        if ( l[i] <= maxlen )
        {
             count ++ ;
        }
    }
    
    printf ( "%d\n" , count ) ;
    }
}
