#include<stdio.h>
#include <string.h>


int main()
{
	int t;
	int l;
	scanf("%d",&t);
	char al[51];
	int a[4];
	int i;
	while(t--)
	{
	for(i=0; i<4; i++)
		a[i]=0;
	scanf("%s",al);
	l=strlen(al);
	
	for(i=0; i<l; i++){
		switch(al[i]){
			case 'R': a[0]++; break;
			case 'G': a[1]++; break;
			case 'B': a[2]++; break;
			case 'W': a[3]++; break;	
			}
			}
	if(a[0]%2==0 && a[1]%2==0 && a[2]%2==0 && a[3]%2==0)
		printf("YES");
		
	else
		printf("NO");		
	printf("\n");
	}
	return 0;
}
