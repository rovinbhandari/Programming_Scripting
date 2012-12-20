#include<iostream>
#include<cmath>
#include<string>
#include<list>

using namespace std;


int function( int i, list<int> array[], int check[], int j)
{
		check[i]=j;
		int kuch;
		list<int>::iterator iter = array[i].begin();
		
		for(iter;iter!=array[i].end();iter++)
		{
			if(check[*iter]==-1)
			{
				if(j==1)
					kuch = function(*iter, array, check, 0);
				else
					kuch = function(*iter, array, check, 1);
				if(kuch==-1)
				 break;
			}
			else if(check[*iter]==j)
				return -1;
			
		}
		if(kuch==-1)
			return -1;
		
		return 0;
	
}
	
	
	
int main(){
	int i,j,k, N;
	i=0;
	j=0;
	k=0;
	int ntest;
	cin>>ntest;
	int random;
	
	for(i=0; i<ntest; i++)
	{
		cin>>N;
		list<int> array[N];
		int nr[N];
		for(j=0; j<N; j++)
		{
			cin>>nr[j];
			for(k=1; k<=nr[j]; k++)
			{
				cin>>random;
				array[j].push_back(random);
				array[random].push_back(j);
			}
		}

		
		int check[N];
		for(j=0; j<N; j++)
			check[j]=-1;
		
		int kuch=0;
		int answer=0;
		for(j=0; j<N; j++)
		{
			if(check[j]==-1)
			{
				kuch=function( j, array, check, 1);	
				if(kuch==0)
					answer++;
				else if(kuch==-1)
				{
					
					break;
				}
			}
			
		}
		if(kuch==0)
		{
			int a=1;
			for(int bh=0; bh<answer; bh++)
			{	
				a*=2;
				a=a%(1000000000+7);
			}
			cout<<a<<endl;
			
		}
		else if(kuch==-1)
			cout<<'0'<<endl;
		
		
	}
return 0;
}
	
	
