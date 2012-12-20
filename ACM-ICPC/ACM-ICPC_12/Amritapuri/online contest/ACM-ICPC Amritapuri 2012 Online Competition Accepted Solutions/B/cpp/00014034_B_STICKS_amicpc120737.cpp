#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#define ModNum 1000000007

using namespace std;

extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
int inpint();
long long inplong();
int L[50002],H[50002],B[50002],W[50002];
long long Diag[50002];
inline int inpint()
{
int noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}
inline long long inplong()
{
long long noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}
int compare(const void *a, const void *b)
{
	return (*(long long int*) a-*(long long int*)  b);
}
inline long long  expo(long long  a, long long  b){
  long long  result = 1;

  while (b){
    if (b&1){
      result *= a;
    }
    b >>=1 ;
    a *= a;
  }

  return result;
}
 int binsearch(long long l[],int x,int low,int high)
{
	int mid;
	if(low>high)
		 return (-1);
	mid=high+low/2;
	return (x<=l[mid]?mid:binsearch(l,x,mid+1,high));
}
inline long long sqrt_1(long long n)
{
	long long x=expo((ceil(32)/2),2);
	while(1)
	{
		long long y=floor((x+floor(n/x))/2);
		if(y>=x)
			return x;
		x=y;
	}
}

int main()
{
	int T,count=0;
	T=inpint();
	while(T--)
	{
	  int N=inpint(),M=inpint(),i=1;
          for(i=0;i<N;i++)
             { L[i]=inpint();
              }
	  //cout<<"g";
          for(i=0;i<M;i++)	
            { H[i]=inpint();B[i]=inpint(),W[i]=inpint();
              Diag[i]=sqrt((expo(H[i],2)+expo(B[i],2)+expo(W[i],2)));
		//cout<<Diag[i]<<endl;
             }
		
	  qsort(Diag,M,sizeof(long long),compare);
          for(i=0;i<N;i++)
	  {
		int val=binsearch(Diag,L[i],0,M-1); 
		if(val!=-1)
			count++;
	   }
		printf("%d\n",count);
		count=0;
		if(T>1)
			getchar();
	
      }
	return 0;
}
	                                       
