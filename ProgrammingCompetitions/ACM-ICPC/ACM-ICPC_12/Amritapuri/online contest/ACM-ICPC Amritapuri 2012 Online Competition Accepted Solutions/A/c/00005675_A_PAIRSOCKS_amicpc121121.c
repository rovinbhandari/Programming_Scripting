#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main()
{

        int t,i=0,len,R,G,B,W,j;
        char *str;
        int *r;
        scanf("%d",&t);
        if(t>=1&&t<=1000)
        {
        r = (int*)malloc(t*sizeof(int));
        while(i<t)
        {
        	str = (char*)malloc(t*sizeof(char));
                scanf("%s",str);
                r[i]=0;
                len = strlen(str);
                
                if(len%2==0&&len<=50)
                {
                	R=0;G=0;B=0;W=0;j=0;
                        while(j<len)
                        {
                                switch(str[j])
                                {
                                        case 'R':
                                                R++;
                                                break;
                                        case 'G':
                                                G++;
                                                break;
                                        case 'B':
                                                B++;
                                                break;
                                        case 'W':
                                                W++;
                                                break;
                                }
                                j++;
                        }
                        
                        if((R%2==0)&&(G%2==0)&&(B%2==0)&&(W%2==0))
                           r[i] = 1; //yes
                        
                        else
                           r[i] = 0; //no
                         
                   
                }
                else
                {
                        r[i] = 0; //no
                }
                i++;
        }
        for(i =0; i<t;i++)
        {
                switch(r[i])
                {
                        case 0:
                                printf("NO");
                                break;
                        case 1:
                                printf("YES");
                                break;
                }
                printf("\n");
                
        }
        }
        return 0;
}
