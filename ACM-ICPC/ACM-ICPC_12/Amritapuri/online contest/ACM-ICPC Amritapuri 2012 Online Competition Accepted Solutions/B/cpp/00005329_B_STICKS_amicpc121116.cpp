#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
#define getcx getchar_unlocked

int t,n,m;
long long ret;
long long l[50005],a[50005],b[50005],c[50005],maxL,allMax,countx;


inline long long inp()
{
    ret=0;
    int ch=getcx();
	//	int sign=1;
    while( ch < '0' || ch > '9' ){ ch=getcx();}
	
    while(  ch >= '0' && ch <= '9' )
	{ret = (ret*10)+ ( ch-'0'); ch=getcx();}
	return ret;
}



int main()
{
	t = inp();
	while(t--)
	{
		countx = 0;
		allMax = 0;
		n = inp();
		m = inp();
//		cout << n << " " << m << endl;
	//	scanf("%d %d",&n,&m);
		for(int xx =0;xx<n;xx++)
		{
//			scanf("%d",&l[xx]);
			l[xx] = inp();
//			cout << l[xx] << endl;
			l[xx] = l[xx]*l[xx];
		}
		for(int xx=0;xx<m;xx++)
		{
//			scanf("%d %d %d",&a[xx],&b[xx],&c[xx]);
			a[xx] = inp();
			b[xx] = inp();
			c[xx] = inp();

			maxL = (a[xx]*a[xx]) + (b[xx]*b[xx]) + (c[xx] * c[xx]);
//			cout << a[xx] << " " << b[xx] << " " << c[xx] <<  " " << maxL[xx] << endl;
			if(maxL > allMax)
				allMax = maxL;
		}
		for(int xx =0;xx<n;xx++)
		{
			if(l[xx] <= allMax)
				countx++;
		}
		cout << countx << "\n";
	}
	return 0;
}