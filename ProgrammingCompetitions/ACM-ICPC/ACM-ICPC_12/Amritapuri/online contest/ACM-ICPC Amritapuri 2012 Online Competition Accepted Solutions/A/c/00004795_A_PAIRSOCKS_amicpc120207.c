#include<stdio.h>
#include<string.h>
struct st{
    char arr[51];
    int ans;
    }apr[1001];

int main()
{
int i,l,t,k=0;
int a=0,b=0,c=0,d=0;
scanf("%d",&t);
int s=t;
while(t!=0)
{apr[k].ans=0;
a=0;
b=0;
c=0;
d=0;
scanf("%s",apr[k].arr);
l=strlen(apr[k].arr);
for(i=0;i<l;i++)
{
if(apr[k].arr[i]=='R')
a++;
if(apr[k].arr[i]=='G')
b++;
if(apr[k].arr[i]=='B')
c++;
if(apr[k].arr[i]=='W')
d++;
}
if(a%2==0 && b%2==0 && c%2==0 && d%2==0)
apr[k].ans=1;
t--; k++;
}
for(k=0;k<s;k++)
{
if(apr[k].ans==1)
printf("YES\n");
else 
printf("NO\n");
}
return 0;
}