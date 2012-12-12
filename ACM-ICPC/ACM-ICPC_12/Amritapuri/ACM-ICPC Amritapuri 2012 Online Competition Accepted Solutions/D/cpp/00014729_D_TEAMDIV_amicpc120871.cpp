#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int BFS(vector<int> &vs, vector< vector<int> > &rivals)
{
	int N=vs.size();

	queue<int> neighbours;

	int start=0;
	for(;start<N;start++)
	{
		while(vs[start]!=0)	start++;
		break;
	}

	if(start>=N)	return 0;

	vs[start]=1;
	neighbours.push(start);

	while(!neighbours.empty()) {
		int currNode = neighbours.front();
		neighbours.pop();
		for(int c1=0;c1<rivals[currNode].size();c1++)
		{
			if(vs[rivals[currNode][c1]]==0)
			{
				neighbours.push(rivals[currNode][c1]);
				vs[rivals[currNode][c1]]=3-vs[currNode];
			} else {
				if(vs[currNode]==vs[rivals[currNode][c1]])
					return -1;
			}
		}
	}
	return 1;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		int noConnected=0;
		vector<int> vs;
		vector< vector<int> > rivals;

		cin>>N;
		for(int c1=0;c1<N;c1++)
		{
			vs.push_back(0);
			vector<int> tempV;
			rivals.push_back(tempV);
		}
		int temp;
		for(int c1=0;c1<N;++c1)
		{
			cin>>temp;
			for(int c2=0;c2<temp;++c2)
			{
				int temp2;
				cin>>temp2;
				rivals[c1].push_back(temp2);
				rivals[temp2].push_back(c1);
			}
		}
		if(N==0){
			cout<<"1"<<endl;
			continue;
		}
		if(N==1){
			cout<<"2"<<endl;
			continue;
		}
		int flag=1;
		while(1)
		{
			int b=BFS(vs, rivals);
			if(b==-1)
			{
				cout<<"0"<<endl;
				flag=0;
				break;
			}
			if(b==0)	break;
			else noConnected++;
		}
		if(flag)
		{
			int ans=1;
			for(int c1=0;c1<noConnected;c1++)
			{
				ans*=2;
				ans=ans%1000000007;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
