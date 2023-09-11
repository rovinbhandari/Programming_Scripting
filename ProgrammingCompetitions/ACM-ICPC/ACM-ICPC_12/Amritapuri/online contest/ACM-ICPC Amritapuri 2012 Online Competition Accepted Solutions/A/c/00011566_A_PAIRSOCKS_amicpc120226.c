#include<stdio.h>
void check(char *s)
{
  int a,i,arr[4]={0};    
  for(i=0;s[i]!='\0';i++)    
    {
      switch(s[i])
	{
	case 'R': arr[0]++;break;
	case 'W': arr[1]++;break;
	case 'B': arr[2]++;break;
	case 'G': arr[3]++;break;
	}	          
    }
  if((arr[0]%2==0)&&(arr[1]%2==0)&&(arr[2]%2==0)&&(arr[3]%2==0))
    printf("YES\n");
  else
    printf("NO\n");
}
int main()
{
  int t,i;
  char s[1001][51];
  scanf("%d",&t);
  for(i=0;i<t;i++)
    scanf("%s",s[i]);
  for(i=0;i<t;i++)
      check(s[i]);
  return 0;
}
