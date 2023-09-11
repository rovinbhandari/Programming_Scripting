#include<stdio.h>
int main()
{       int t;
        int i=0;
	int m=0;
        char s[50];
	int flag[1000];
        scanf("%d",&t);
        while(t>0)
        {       scanf("%s",&s);
                int cw=0;
		int cb=0;
		int cg=0;
		int cr=0;
                while(s[i]!='\0')
                {       if(s[i]=='R')
                        {       cr=cr+1;
                        }
                        if(s[i]=='B')
                        {       cb=cb+1;
                        }
                        if(s[i]=='W')
                        {       cw=cw+1;
                        }
                        if(s[i]=='G')
                        {       cg=cg+1;
                        }
                        i++;
                }
                if(cr%2==0 && cb%2==0 && cw%2==0 && cg%2==0)
                      flag[m]=1;
                else
                        flag[m]=0;
                t--;
		m++;
                i=0;
        }
	for(i=0;i<=m-1;i++)
	{	if(flag[i]==1)
			printf("YES\n");
		else
			printf("NO\n");
	}	
        return 0;
                                                                                  
}
