#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<fstream>
using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	int num_cases;
	cin>>num_cases;
	int i=0,j,temp;
	int num_sticks,num_boxes;
	int fitting_sticks;
	long int max_fit_length;
	long int max_of_all_boxes;
	long int length,height,breadth;
	while(i<num_cases)
	{
		fitting_sticks=0;
		cin>>num_sticks;
		cin>>num_boxes;
		vector<int> stick_length;
		max_of_all_boxes=-1;
		for(j=0;j<num_sticks;j++)
		{
			cin>>temp;
			stick_length.push_back(temp);
		}
		for(j=0;j<num_boxes;j++)
		{
			cin>>length;
			cin>>breadth;
			cin>>height;
			max_fit_length=sqrt((length*length)+(breadth*breadth)+(height*height));
			if(max_fit_length>max_of_all_boxes)
			{
				max_of_all_boxes=max_fit_length;
			}
		}
		for(j=0;j<num_sticks;j++)
		{
			if(max_of_all_boxes>=stick_length.at(j))
			{
				fitting_sticks++;
			}
		}
		cout<<fitting_sticks<<"\n";
		i++;
	}
	return 0;
}
