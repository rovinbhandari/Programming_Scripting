#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main()
{
        char **s;
        int n,i,count,k=0,r=0,g=0,b=0,w=0;
        scanf("%d",&n);
        if(n<1 || n>1000)
        {
                return 0;
        }
        s=(char**)malloc(sizeof(char*)*n);
        for(i=0;i<n;i++)
        {
                s[i]=(char*)malloc(sizeof(char)*50);
                scanf("%s",s[i]);
        }
				for(i=0;i<n;i++)
				{
								k=0;
								if(strlen(s[i])>50)
								{
									return 0;
								}
								
									while(s[i][k]!='\0')
									{
										if(s[i][k]!='R' && s[i][k]!='G' && s[i][k]!='B' && s[i][k]!='W')
										{
											return 0;
										}
										k++;
									}
				}
				k=0;
        for(i=0;i<n;i++)
        {
                while(s[i][k]!='\0')
                {
                        if(s[i][k]=='R')
                        {
                                r++;
                        }
                        else if(s[i][k]=='G')
                        {
                                g++;
                        }
                        else if(s[i][k]=='B')
                        {
                                b++;
                        }
                        else if(s[i][k]=='W')
                        {
                                w++;
                        }
                        k++;
                }
                if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
                {
                        printf("YES\n");
                }
                else
                {
                        printf("NO\n");
                }
                r=0;
                g=0;
                w=0;
                b=0;
								k=0;
        }
        return 0;
}
