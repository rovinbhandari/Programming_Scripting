#include<stdio.h>
#include<string.h>
int main()
{
int T,w,x,y,z,i,j=0,b[1000];
char a[50];
scanf("%d",&T);
if(1<=T&&T<=1000)
while(T)
{
w=0;
x=0;
y=0;
z=0;
scanf("%s",a);
for(i=0;i<strlen(a);i++)
{
	if(a[i]=='R'||a[i]=='r')
	 w++;
	else if(a[i]=='W'||a[i]=='w')
	 x++;
	else if(a[i]=='G'||a[i]=='g')
	 y++;
	else if(a[i]=='B'||a[i]=='b')
	 z++;
	 else
	 {
		printf("wrong input, please enter w,g,r and b only");
		break;
	 }
}
if((w%2==0)&&(x%2==0)&&(y%2==0)&&(z%2==0))
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

