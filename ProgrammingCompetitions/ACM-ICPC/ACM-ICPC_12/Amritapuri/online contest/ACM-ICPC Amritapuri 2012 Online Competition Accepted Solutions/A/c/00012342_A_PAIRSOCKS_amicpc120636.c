#include<stdio.h>

int flag[50];
int main()
{
char str[100];
int i,j=0,t,r,g,b,w,len;
scanf("%d",&t);

for(i=0;i<t;i++)
{
    scanf("%s",str);

    j=0;
    while(str[j]!='\0')
    {
        j++;
    }
    len=j;


    if(!(len%2))
    {


    r=0;
    g=0;
    b=0;
    w=0;
    j=0;
    while(str[j]!='\0')
    {

        switch(str[j])
        {
            case 'R':
                      r+=1;
                     break;

            case 'G':
                      g+=1;
                      break;

            case 'B':
                      b+=1;
                      break;

            case 'W':
                      w+=1;
                      break;


        }
        j++;

    }
        if( (!(r%2)) &&(!(g%2)) && (!(b%2)) && (!(w%2)) )
         printf("YES\n");
        else
         printf("NO\n");
    }
    else
         printf("NO\n");


}

 return 0;

}

