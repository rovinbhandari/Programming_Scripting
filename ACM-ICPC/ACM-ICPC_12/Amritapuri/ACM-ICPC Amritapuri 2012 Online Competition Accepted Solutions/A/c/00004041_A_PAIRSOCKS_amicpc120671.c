#include <stdio.h>
#include <string.h>
int main ()
{
	int i,j,k,n,l;
	scanf ("%d",&n);

	int flag;
	
	while (n--){
		flag=0;
		char a[100];
		int b[50]={0};
		scanf ("%s",a);
		l=strlen (a);
		for (i=0;i<l;i++){
			int w = a[i];
			b[w-65]++;
		}
		for (i=0;i<50;i++){
			if ((b[i]%2)!=0){
				printf ("NO\n");
				flag=1;
				break;
			}
			
		}
		if (flag==0){
			printf ("YES\n");
		}
		
	}
	return 0;
}
