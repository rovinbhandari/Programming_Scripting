#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>


using namespace std;

int M= 1000000007;

long long int pow(int n)
{
	long long int ans=1;
	long long int x=2;

	while(n)
	{
		if(n&1)
		{
			ans = (ans*x)%M;
		}
		x=(x*x)%M;
		n=n/2;
	}
	return ans;
}


int main()
{

	int test_cases,i,j,n,k,num;
	scanf("%d",&test_cases);

	while(test_cases--)
	{

		scanf("%d",&n);
		vector< vector<int> > array(n);
		int visited[n],c[n];

		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			for(j=0;j<k;j++)
			{
				scanf("%d",&num);
				array[i].push_back(num);
				array[num].push_back(i);
			}
		}

		for(i=0;i<n;i++)
		{	
			visited[i]=0;
			c[i]=-1;
		}

		queue<pair<int,int> > mq;
		int components=0,total=0,flag=0,ver,color;

		for(i=0;i<n;i++)
		{	
			if(total==n)
				break;

			if(visited[i]==0)
			{
				mq.push(make_pair(i,0));

				while(!mq.empty())
				{
					ver = mq.front().first;
					color = mq.front().second;

					if(visited[ver]==0)
					{

						visited[ver]=1;
						total++;
						c[ver]=color;
						mq.pop();

						for(j=0;j<array[ver].size();j++)
						{

							if(array[ver][j]!=ver && c[j]!=-1 && c[ver]==c[array[ver][j]])
							{
								flag=1;
								break;
							}

							if(visited[array[ver][j]]==0)
							{
								mq.push(make_pair(array[ver][j],1-color));		
							}
						}

					}
					else
						mq.pop();
				}
				components++;
			}

		}
		
		if(flag==1)
			printf("0\n");
		else
		{
			long long int ans= pow(components);
			printf("%lld\n",ans);
		}

	}

		


return 0;

}
