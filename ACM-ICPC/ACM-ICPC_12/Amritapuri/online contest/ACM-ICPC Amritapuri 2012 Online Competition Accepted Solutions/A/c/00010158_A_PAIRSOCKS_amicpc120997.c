#include<stdio.h>
#include<string.h>
int main()
{
int T,c1,c2,c3,c4,i,j=0,b[1000];
char c[50];
scanf("%d",&T);
if(1<=T&&T<=1000)
while(T)
{
c1=0;
c2=0;
c3=0;
c4=0;
scanf("%s",c);
for(i=0;i<strlen(c);i++)
{
	if(c[i]=='R'||c[i]=='r')
	 c1++;
	else if(c[i]=='W'||c[i]=='w')
	 c2++;
	else if(c[i]=='G'||c[i]=='g')
	 c3++;
	else if(c[i]=='B'||c[i]=='b')
	 c4++;
	 else
	 {
		printf("wrong input, please enter w,g,r and b only");
		break;
	 }
}
if((c1%2==0)&&(c2%2==0)&&(c3%2==0)&&(c4%2==0))
	b[j++]=1;
	else 
	 b[j++]=0;
T--;
}
for(i=0;i<j;i++)
{

if(b[i]==1)
printf("YES");
else
	printf("NO");
	printf("\n");
}
return 0;
}

