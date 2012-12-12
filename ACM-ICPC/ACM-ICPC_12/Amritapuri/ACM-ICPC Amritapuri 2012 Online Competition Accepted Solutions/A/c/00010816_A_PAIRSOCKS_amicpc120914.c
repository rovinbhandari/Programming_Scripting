#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
int T=0,i=0,j=0,k=0,x=0;
int countr=0,countg=0,countb=0,countw=0;
int arr[1000];
char N[50];
scanf("%d",&T);
if(T>=1 && T<=1000)
{
       for(i=0;i<T;i++)
       {
	     for(x=0;x<50;x++)
	     {
	     N[x]='\0';
	     }
	     j=0;
	     countr=0;
	     countg=0;
	     countb=0;
	     countw=0;
	     scanf("%s",N);
	     j=strlen(N);
	     if(j<=50)
	     {
		    for(k=0;k<j;k++)
		    {
			if(N[k]=='R')
			countr++;
			else if(N[k]=='G')
			countg++;
			else if(N[k]=='B')
			countb++;
			else if(N[k]=='W')
			countw++;
			else
			exit(0);
		    }
	    }
	    else
	    exit(0);
	    if(countr%2==0 && countg%2==0 && countb%2==0 && countw%2==0)
	    arr[i]=1;
	    else if(countr%2!=0 || countg%2!=0 || countb%2!=0 || countw%2!=0)
	    arr[i]=0;
       }
}
else
exit(0);
for(i=0;i<T;i++)
{
      if(arr[i]==1)
      printf("YES\n");
      else if(arr[i]==0)
      printf("NO\n");

}
return (0);
}
