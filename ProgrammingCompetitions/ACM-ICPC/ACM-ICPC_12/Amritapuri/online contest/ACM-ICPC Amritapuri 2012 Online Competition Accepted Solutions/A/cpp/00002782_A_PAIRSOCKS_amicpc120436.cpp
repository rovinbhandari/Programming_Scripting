#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>

using namespace std;

int main()
{

 int i,t,j;
 char str[55];
 int a[26],ans;

 scanf("%d",&t);

 while(t--)
 {
	ans = 1;
  
 	scanf("%s",str);


	memset(a,0,sizeof(a));
 	
	for(i=0;i<strlen(str);i++)
	{
		a[str[i]-'A']++;

	}	
 		
	for(i=0;i<26;i++)
	{
		if(a[i]%2==1)
		{
			ans = 0;
			break;
		}
	}

	if(ans)
		printf("YES\n");
	else
		printf("NO\n");

 }

return 0;

}
