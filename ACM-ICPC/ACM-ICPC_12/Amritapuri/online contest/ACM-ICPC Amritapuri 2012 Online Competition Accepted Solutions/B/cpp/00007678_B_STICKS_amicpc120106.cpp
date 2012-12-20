#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(){
int no_of_tcs;
long int m;
long int n;
long int length;
vector<long int> sticks;
long int l;
long int b;
long int h;
long int diag;
long int max;
long int count;
int i = 0;
cin >> no_of_tcs;
int j,k;
while(i < no_of_tcs){
	cin >> m;
	cin >> n;
	sticks.clear();
	max = 0;
	count = 0;
	for(j = 0; j < m ; j++){
		cin >> length;
		sticks.push_back(length);
	}
	for(k = 0; k < n ; k++){
		cin >> l;
		cin >> b;
		cin >> h;
		diag = sqrt(l*l + b*b + h*h);
		if(max < diag){max = diag;}
	}
	for(j = 0; j < sticks.size() ; j++){
		if(sticks[j] <= max){count ++;}
	}
	cout << count << endl;
	i++;
}
return 0;
}
