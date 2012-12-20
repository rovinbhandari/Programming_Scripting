#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
int t,i,flag;
char c[100];
int f[10];
scanf("%d",&t);

while(t--)
{  flag=0;
  scanf("%s",c);
  memset(f,0,sizeof(f));
  for(i=0; c[i]!='\0'; i++)
  {
      if(c[i]=='R') f[1]++;
	  else if (c[i]=='G') f[2]++;
	  else if(c[i]=='B') f[3]++;
	  else f[4]++;
	}
   for(i=1;i<5; i++)
	{
		if(f[i]&1) { flag=1; break;}
	}
  if(flag==0)
   printf("YES\n");
  else
   printf("NO\n");
  }
return 0;
}  
   
