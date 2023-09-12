#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct str
{
	vector <int> ne;

};
int powr(int count)
{
	long long r=1;
	while(count--)
	r=(r*2)%1000000007;
return r%1000000007;
}
int main()
{
	int t,n,k,temp,count;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		int track[20001]={0};
		str neigh[n];
		count=0;

		for(int i=0;i<n;++i)
		{

			cin>>k;
			for(int j=0;j<k;++j)
			{
				cin>>temp;
				neigh[i].ne.push_back(temp);
				neigh[temp].ne.push_back(i);
			}


		}
   
    int error=0;
		
		for(int i=0;i<n;++i)
		{
			if(track[i]==0)
			{
		
			count++;
			
			queue<int> q;
				q.push(i);

				track[i]=1;
				
				while(!q.empty())
				{

					int f=q.front();
					
					    q.pop();
					for(int j=0;j<neigh[f].ne.size();++j)
					{
						    if(track[neigh[f].ne[j]]==0)
						    {
						    	
							q.push(neigh[f].ne[j]);
                             track[neigh[f].ne[j]]=-track[f];
						 }
						 else if(track[neigh[f].ne[j]]!=-track[f])
						 {error=1;
						 	break;}

							

					}
					if(error==1)
						break;
				}
			}
		}
		if(error==0)
     cout<<powr(count)<<endl;
 else cout<<0<<endl;
	}
}