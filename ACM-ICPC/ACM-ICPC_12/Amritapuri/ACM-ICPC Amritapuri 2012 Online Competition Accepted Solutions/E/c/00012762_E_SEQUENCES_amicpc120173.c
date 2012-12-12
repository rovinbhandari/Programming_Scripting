#include<stdio.h>

int m[3000000][3];
/*
void prin(int n)
{
	int i,j,k;
	printf("\n\nPrinting\n");
	for(i=1;i<=n;i++)
	{
		if(!(i&(i-1))) printf("\n");
		printf("%d|%d|%d ",m[i][0],m[i][1],m[i][2]);
	}
	printf("\n\n");
}
*/

int mx(int a, int b)
{
	if(a<b) return b;
	return a;	
}

int qu(int a,int b,int k,int ol,int or,int lz,int ro)
{
	//	printf("Q l %d,r %d,lo %d,ro %d,l0 %d,r1 %d\n",a,b,ol,or,lz,ro);
	if(a==b) return ol;
	if((a/2)==(b/2))
	{
		return mx(ol+ro,or+lz);
	}

	if(a==((a/2)*2))  //left is left
	{
		ol=mx(ol+m[a+1][2],lz+m[a+1][0]);
		lz=lz+m[a+1][1];
	}

	if(b!=((b/2)*2))	//right is right
	{
		or=mx(or+m[b-1][1],ro+m[b-1][0]);
		ro+=m[b-1][2];
	}
	return qu(a/2,b/2,k,ol,or,lz,ro);
}

//0=Sol, 1=0,2=1
int main()
{
	int i,j,k,l,t,n,q;
	char a[1000004];
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",a);


		j=1;
		while(j<n) j*=2;
		for(k=j;k<2*j;k++)
		{
			if((k-j)<n)
			{
				m[k][0]=1;

				m[k][1]=((a[k-j]=='0')?1:0);
				m[k][2]=((a[k-j]=='0')?0:1);
			}
			else
			{
				m[k][0]=m[k][1]=m[k][2]=0;
			}
		}
		for(k=j-1;k>0;k--)
		{
			m[k][0]= mx(m[2*k][0]+m[2*k+1][2],m[2*k+1][0]+m[2*k][1]);
			m[k][1]=m[2*k][1]+m[2*k+1][1];
			m[k][2]=m[2*k][2]+m[2*k+1][2];
		}
		//prin(j+j);
		scanf("%d",&q);
		//printf("M%d %s %d\n",n,a,q);
		for(l=0;l<q;l++)
		{
			scanf("%d%d",&i,&k);
			printf("%d\n", qu(j+i-1,j+k-1,j,1,1,(a[i-1]=='0'?1:0),(a[k-1]=='1'?1:0)));
		}
	}

	return 0;
}
