#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;


int T;
int box, st,x,y,z,w;
int i,j,n2;
long long int n[100000];
long long int b[100000][5];
long long int cc, max1;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&st,&box);
		for(i=0;i<st;i++)
		{
			scanf("%lld",&n[i]);
		}
		for(i=0;i<box;i++)
		{
			scanf("%lld%lld%lld",&b[i][0],&b[i][1],&b[i][2]);
			b[i][3]=(b[i][0]*b[i][0])+(b[i][2]*b[i][2])+(b[i][1]*b[i][1]);
		}
		max1 = 0;
		for(i=0;i<box;i++)
		{
			if(max1<b[i][3])
				max1=b[i][3];
		}
		cc=0;
		for(i=0;i<st;i++)
		{
			if( (n[i]*n[i])<=max1)
				cc++;
		}
		printf("%lld\n",cc);
	}
	return 0;
}
