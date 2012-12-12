#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int T; cin >> T;
	for (int j=0; j<T; j++)
	{
	int N,M;
	cin >> N >> M;
	vector<double> sticks;
	for (int i=0; i<N; i++) {double t; cin >> t; sticks.push_back(t);}
	vector<double> boxes;
	for (int i=0; i<M; i++) {double t1,t2,t3; cin >> t1 >> t2 >> t3; double t4= sqrt(pow(t1,2) + pow(t2,2) + pow(t3,2)); boxes.push_back(t4);}
	
	double largestBox=0;
	for (int i=0; i<M; i++) {if(boxes[i]>largestBox) largestBox= boxes[i];}
	long count=0;
	for (int i=0; i<N; i++) {if (sticks[i]<=largestBox) count++;}
	cout << count << endl;
}
}
