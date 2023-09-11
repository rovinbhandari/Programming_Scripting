#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int num,i,j,k,len;
char **a,**c,temp;

scanf("%d",&num);
/*if(num>1000||num<1)
{
exit(0);
}*/
a=(char **)calloc(num,sizeof(char*));
for(i=0;i<num;++i)
{
a[i]=(char *)calloc(50,sizeof(char));
}

for(i=0;i<num;++i)
{
scanf("%s",a[i]);
/*if(strlen(a[i])>50)
{
exit(0);
}
len=strlen(a[i]);
	for(j=0;j<len;++j)
	{
		if(a[i][j]!='R'&&a[i][j]!='G'&&a[i][j]!='B'&&a[i][j]!='W')
		{
			exit(0);
			
		}
	}*/
			
}

for(i=0;i<num;++i)
{
if(num<1||num>1000)
{
exit(0);
}
len=strlen(a[i]);
if(strlen(a[i])>50)
{
exit(0);
}
	for(j=0;j<len;++j)
	{
		if(a[i][j]!='R'&&a[i][j]!='G'&&a[i][j]!='B'&&a[i][j]!='W')
		{
			exit(0);
			
		}
	}

}

for(i=0;i<num;++i)
{
	len=strlen(a[i]);
	for(j=0;j<len-1;++j)
	{
		
		for(k=j+1;k<len;++k)
		{
			if(a[i][j]>a[i][k])
			{
				temp=a[i][j];
				a[i][j]=a[i][k];
				a[i][k]=temp;
			}

		}
				
	}

}
char prev;
int flag,count=0;
/*for(i=0;i<num;++i)
{ABCD
printf("%s\n%d\n",a[i],strlen(a[i]));
}*/
for(i=0;i<num;++i)
{
	len=strlen(a[i]);
	flag=0;	
	count=1;
	prev=a[i][0];
	for(j=1;j<len;++j)
	{

		if(a[i][j]==prev)
		{
			++count;
		}

		else if(count%2!=0)
		{
			flag=1;
			break;
		}
		else
		{
		count=1;
		prev=a[i][j];
		}
	

	}
	if(count%2==0&&flag==0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");

	}
}
return 0;
}

