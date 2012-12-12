#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		int count=0;
		int N,L,H;
		cin>>N>>L>>H;
		vector<int> num(N);
		int x;
		for(int j=0;j<N;j++)
		{
			cin>>x;
			num.at(j)=x;
		}
		make_heap(num.begin(),num.end());
		sort_heap(num.begin(),num.end());
		int p=0;
		int q,r;
		while(p<=N-3)
		{
//			cout<<"Enter"<<endl;
			q=p+1;
			while(q<=N-2&&(num.at(p)+num.at(q)<H))
			{
				int lower_limit=L-num.at(p)-num.at(q);
				if(lower_limit<0)
					lower_limit=0;
				int upper_limit=H-num.at(p)-num.at(q);
				r=q+1;
				int t=N-1;
				int count_prev=count;
				while(r<t)
				{
					//cout<<"r="<<r<<" t="<<t<<" values="<<num.at(r)<<" "<<num.at(t)<<endl;
					if(num.at((r+t)/2)>=lower_limit)
					{
						t=(r+t)/2;
					}
					else
					{
						r=(r+t+1)/2;
					}
				}
				int low_limit=t;
				//cout<<"lower="<<t<<endl;
				r=q+1;
				t=N-1;
				while(r<t)
				{
					if(num.at((r+t)/2)<=upper_limit)
						r=(r+t+1)/2;
					else
						t=(r+t)/2;
				}
				
				int up_limit=t;
				if(num.at(up_limit)>upper_limit)
					up_limit--;
				//cout<<"upper="<<t<<endl;
				if(low_limit!=up_limit)
					count+=(up_limit-low_limit+1);
				else
				{
					int sum=num.at(p)+num.at(q)+num.at(low_limit);
					if(sum>=L&&sum<=H)
						count++;
				}
				//cout<<num.at(p)<<" "<<num.at(q)<<" "<<count-count_prev<<endl;
				q++;
			}
			p++;
		}
		cout<<count<<endl;
	}
	return 0;
}
