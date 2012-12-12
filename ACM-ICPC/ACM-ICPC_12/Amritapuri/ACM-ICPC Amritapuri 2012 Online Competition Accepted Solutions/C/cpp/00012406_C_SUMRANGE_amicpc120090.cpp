#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>


using namespace std;

int hash[1000005];
long long int prefix[1000005];

int main()
{

	int test_cases,n,i,l,h,num,j,k,sum,cnt;

	scanf("%d",&test_cases);

	while(test_cases--)
	{

		scanf("%d %d %d",&n,&l,&h);
		vector<int> array;
		
		for(i=0;i<1000005;i++)
			hash[i]=0;

		for(i=0;i<n;i++)
		{	scanf("%d",&num);
			if(hash[num]==0)
			{	array.push_back(num);
				hash[num]++;
			}
			else
				hash[num]++;
		}

		long long int sum=0;
		for(i=0;i<=1000005;i++)
		{
			sum=sum+hash[i];
			prefix[i]=sum;
		}



		sort(array.begin(),array.end());
		int l1,l2,mx;
		long long int d,cnt=0,b;

		for(i=0;i<n;i++)
		{
			if((array[i]*3) >=l && (array[i]*3)<=h)
			{
				b=hash[array[i]];
				cnt+=(b*(b-1)*(b-2))/6;

			}
			for(j=i+1;j<n;j++)
			{
				mx = array[j];
				sum = array[i]+array[j];
				if(sum>h )
					continue;
			
				l1 = l-sum;
				l2 = h-sum;
				
				if(sum + array[j]>=l && sum+array[j]<=h)
				{
					cnt += ((hash[array[j]]*(hash[array[j]]-1))/2)*hash[array[i]];
				}
				
				if(sum + array[i]>=l && sum+array[i]<=h)
				{
					cnt += ((hash[array[i]]*(hash[array[i]]-1)/2))*hash[array[j]];
			        }	

				if(mx>l2)
					continue;

				if(l1 > mx)
				{
					d = prefix[l2]-prefix[l1-1];
				}
				else
				{
					d = prefix[l2]-prefix[mx];
				}

				cnt = cnt + d*hash[array[i]]*hash[array[j]];

			}
		}
	printf("%lld\n",cnt);	
	}
return 0;

}
