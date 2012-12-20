/*
 * =====================================================================================
 *
 *       Filename:  q2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2012 09:54:35 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aman Shah (aman), amanforindia@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
#include<stdio.h>
using namespace std;
int main ( )
{
    long long int t, n, m, l[50006], a[50006], b[50006], c[50006], count;
    long long int max, temp;
    scanf("%lld", &t);
    while(t--){
        max=-10;
        count=0;
        scanf("%lld%lld", &n, &m);
        for(int i=0;i<n;i++){
            scanf("%lld", &l[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
            temp=a[i]*a[i]+b[i]*b[i]+c[i]*c[i];
            if(max<temp)
                max=temp;
        }
        for(int i=0;i<n;i++){
            if(l[i]*l[i]<=max){
                count++;
            }
        }

        printf("%lld\n", count);
    }
    char c1,c2;
    scanf("%c%c",&c1,&c2);

    return 0;
}				/* ----------  end of function main  ---------- */
