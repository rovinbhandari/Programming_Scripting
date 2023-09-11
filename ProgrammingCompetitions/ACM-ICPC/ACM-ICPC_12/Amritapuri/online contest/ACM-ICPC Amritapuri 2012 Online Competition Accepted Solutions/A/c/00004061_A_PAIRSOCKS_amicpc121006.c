#include<stdio.h>


void main()
{

int i ;

scanf("%d",&i);

int out[i];
int k=0;

for(k=0;k<i;k++)

{


char s[50];


scanf("%s",s);



int red = 0;
int green = 0;
int blue = 0;
int white = 0;

int j=0;

while(s[j]!='\0')

{

if(s[j]=='R')
red++;
else if(s[j]=='G')
green++;
else if(s[j]=='B')
blue++;
else if(s[j]=='W')
white++;
j++;
}

if((red%2 ==0)&& (green%2 ==0)&& (blue%2 ==0) && (white%2 ==0))
out[k]=1;

else 

out[k]=0;


}



for(k=0;k<i;k++)

{
if(out[k]==1)
printf("YES");
else
printf("NO");
printf("\n");

}

}
