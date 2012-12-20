#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() 
{
    int t;
    scanf("%d ",&t);
    long n, m, l1[50000], l,b,h,sum=0, count=0;
    for( ;t>0;t--)
    {
	count=0;
	sum=0;
	scanf("%ld %ld", &n , &m);
	for(int i=0;i<n;i++){
	scanf("%ld", &l1[i]);	
	}
	for(int i=0;i<m;i++){
	scanf("%ld %ld %ld",&l,&b,&h);
	if(sum<sqrt(l*l+b*b+h*h))
	sum=sqrt(l*l+b*b+h*h);
	}
	for(int i=0;i<n;i++)
	if(l1[i]<=sum)
	count++;
	
	printf("%ld\n", count);
    }
    //system("pause");
    return 0;

}
