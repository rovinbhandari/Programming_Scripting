#include<stdio.h>
int check(char []);
int main()
{
  int i,n;
  char str[51];
  scanf("%d",&n);
  int flag[n];
  for(i=0;i<n;i++)
    {
      scanf("%s",str);
      flag[i]= check(str);
    }
  for(i=0;i<n;i++)
    {
      if(flag[i])
	printf("NO\n");
      else 
	printf("YES\n");
    }  
  return 0;
}

int check(char str[])
{
  int i,r=0,g=0,b=0,w=0;
  for(i=0;str[i]!='\0';i++)
    {
      switch(str[i])
	{
	case 'R': r++;
	  break;
	case 'G': g++;
	  break;
	case 'W': w++;
	  break;
	case 'B' : b++;
	  break;
	default:
	  return 1;
	}
    }
  if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
    return 0;
  else 
    return 1;
}
