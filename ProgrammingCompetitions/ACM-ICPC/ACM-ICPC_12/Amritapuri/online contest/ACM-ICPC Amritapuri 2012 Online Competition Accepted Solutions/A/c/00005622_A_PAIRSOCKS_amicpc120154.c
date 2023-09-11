#include<stdio.h>
#include<string.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		char str[52];
		scanf("%s",str);
		int l=strlen(str);
		if(l%2!=0){
			printf("NO\n");
			continue;}
		int j,r=0,b=0,g=0,w=0;
		for(j=0;j<l;j++){
			if(str[j]=='R')
				r++;
			else if(str[j]=='B')
				b++;
			else if(str[j]=='G')
				g++;
			else if(str[j]=='W')
				w++;
		}
		if(r%2==0 && b%2==0 && g%2==0 && w%2==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
