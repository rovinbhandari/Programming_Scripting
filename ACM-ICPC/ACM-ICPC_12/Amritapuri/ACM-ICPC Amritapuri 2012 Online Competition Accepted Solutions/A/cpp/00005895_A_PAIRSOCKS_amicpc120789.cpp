#include<iostream>
using namespace std;
#include<stdlib.h>
main()
{
	int test,i,j,k,count[4],count1[1000],l;
	char input[50];
	cin>>test;
	for(i=0;i<test;i++)
	{
		count1[i]=0;
	}
	for(i=0;i<test;i++)
	{
	 for(l=0;l<4;l++)
        {
                count[l]=0;
        }

		cin>>input;	
		j=0;
		while(input[j]!='\0')
		{
			switch(input[j])
			{
				case 'R':
					count[0]=count[0]+1;
					break;
				case 'G':
					count[1]=count[1]+1;
					break;
				case 'B':
					count[2]=count[2]+1;
					break;
				case 'W':
					count[3]=count[3]+1;
					break;
				default:
					exit(1);
			}
			j++;

		}
		for(k=0;k<4;k++)
		{
			if(count[k]%2==0)
			{
				count1[i]+=1;
			}
			else
			{
				count1[i]+=0;
			}
		}
	}
	for(i=0;i<test;i++)
	{
		if(count1[i]==4)
		{
			cout<<"YES"<<"\n";
		}
		else
			cout<<"NO"<<"\n";
	}	
}
