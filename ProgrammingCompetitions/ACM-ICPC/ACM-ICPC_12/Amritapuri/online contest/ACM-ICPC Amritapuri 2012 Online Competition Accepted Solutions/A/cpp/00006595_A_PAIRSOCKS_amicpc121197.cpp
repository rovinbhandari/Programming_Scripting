#include<iostream>
#include<string.h>


using namespace std;

int check(char s[],int n)
{
int i,j,cr=0,cg=0,cb=0,cw=0;
char x;
if((n%2)==0)
{
 for(i=0;i<n;i++)
 {
switch(s[i])
{
 case 'r':
	cr++; 
	break;
 case 'R':
	cr++;
	break;
 case 'b':
	cb++;
	break;
 case 'B':
	cb++;
 	break;
 case 'g':
 	cg++;
	break;
 case 'G':
	cg++;
	break;
 case 'w':
	cw++;
	break;
 case 'W':
	cw++;
	break;
 default:
	break;
}
}

if((cr%2==0)&&(cb%2==0)&&(cg%2==0)&&(cw%2==0))
{
return 1;
}
else
return 0;

}
else
return 0;

}

int main(void)
{
 char str[50];
 long test;
 int i,n,ans[1000];
 cin>>test;
 for(i=0;i<test;i++)
 {
 	cin>>str;
 	n=strlen(str);
	ans[i]=check(str,n);
 }
for(i=0;i<test;i++)
{
 if(ans[i]==1)
 cout<<"YES"<<endl;
 else
 cout<<"NO"<<endl;
}
return 0;
}
   
