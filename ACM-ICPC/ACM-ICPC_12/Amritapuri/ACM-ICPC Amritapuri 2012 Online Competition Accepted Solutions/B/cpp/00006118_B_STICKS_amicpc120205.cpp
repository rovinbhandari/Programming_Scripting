#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,m;
		int count = 0;
		cin>>n>>m;
		double stick[n],dig = 0, box[3],max_box = 0;
		
		for(int i = 0; i<n; i++)
			cin>>stick[i];
		for(int i = 0; i<m; i++)
		{
			cin>>box[0]>>box[1]>>box[2];
			dig = sqrt((box[0]*box[0])+(box[1]*box[1])+(box[2]*box[2]));
			if(dig > max_box)
				max_box = dig;
		}
		for(int i = 0; i<n; i++)
		{
			if(stick[i] < max_box || (stick[i] - max_box) == 0.000000)
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;	
}
