#include<stdio.h>
#include<string.h>
int main()
{
 	int t;
 	scanf("%d",&t);
 	while(t--)
 	{
	 		  char a[1001];int r=0,g=0,w=0,b=0,l=0;
	 		  scanf("%s",&a);l=strlen(a);
	 		  for(int i=0;i<l;i++)
	 		  {
			   		  if(a[i]=='R')
			   		  r++;
			   		  else if(a[i]=='B')
			   		  b++;
			   		  else if(a[i]=='W')
			   		  w++;
			   		  else
			   		  g++;
  		  }
  		  if(r%2==0 && b%2==0 && g%2==0 &&w%2==0)
  		  printf("YES\n");
  		  else
  		  printf("NO\n");
	 		  
  }
  return 0;
}
