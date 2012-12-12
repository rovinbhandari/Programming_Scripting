#include<iostream>
#include<string>
using namespace std;
//AKSHAY PRATAP SUNNY
int  main()
{
	string str;
	int count1=0,count2=0,count3=0,count4=0,i,j,T,size;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		cin>>str;
		size=str.size();
		count1=0,count2=0,count3=0,count4=0;
		for(j=0;j<size;j++)
		{
			if(str[j]=='R')
				count1++;
			if(str[j]=='G')
				count2++;
			if(str[j]=='B')
				count3++;
			if(str[j]=='W')
				count4++;
		}
		if((count1%2==0)&&(count2%2==0)&&(count3%2==0)&&(count4%2==0))
			cout<<"YES"<<"\n";
		else 
			cout<<"NO"<<"\n";
	}
	return 0;
}