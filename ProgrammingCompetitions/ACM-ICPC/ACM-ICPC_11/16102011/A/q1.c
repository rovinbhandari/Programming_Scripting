#include<stdio.h>
int check(int a)
{int s;
int b[10]={0,0,0,0,0,0,0,0,0,0};
while(a>0)
{s=a%10;
b[s]++;
if(b[s]==3)
return 0;
a/=10;
}
return 1;
}


void main()
{
long int t,a,b,q;
int count=0;
scanf("%d", &t);

while(t--)
{
scanf("%d", &a);
scanf("%d", &b);
while(a<=b)
{
if(check(a++));
count++;
}

}
printf("%d\n",count);
}

