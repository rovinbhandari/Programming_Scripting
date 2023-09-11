#include<stdio.h>
#include<string.h>
void main()
{
		int t,r=0,g=0,b=0,w=0,count=0,jl=0,i;
		char in[100],ch;
		char *p;
		scanf("%d",&t);
		while(count<t)
		  {
				count++;
				scanf("%s",in);
				jl=strlen(in);
				p=in;
				for(i=0;i<jl;i++)
				{   ch=*p;
					 p++;
					 switch(ch)
					 {
						  case 'R':r++;
									  break;
						  case 'G':g++;
									 break;
						  case 'B':b++;
									 break;
						  case 'W':w++;
									 break;
					 }
				}
				if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
					 printf("YES\n");
				else
					 printf("NO\n");
				r=0;g=0;b=0;w=0;

		  }

}
