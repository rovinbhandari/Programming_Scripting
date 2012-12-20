#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){

int number_of_test_cases;
cin>>number_of_test_cases;
string str[number_of_test_cases];
for(int i=0;i<number_of_test_cases;i++){
	cin>>str[i];
}

int str_size=0;
int R_count=0;
int G_count=0;
int B_count=0;
int W_count=0;

for(int i=0;i<number_of_test_cases;i++){
	for(int j=0;str[i][j]!='\0';j++){
		switch(str[i][j]){
			case 'R':R_count++;
				break;
			case 'G':G_count++;
				break;
			case 'B':B_count++;
				break;
			case 'W':W_count++;		
				break;
			}
		}
	if(R_count%2==0 && G_count%2==0 && B_count%2==0 && W_count%2==0){
		cout<<"YES"<<endl;
		}
		else {
		cout<<"NO"<<endl;
		}
	R_count=0;
	G_count=0;
	B_count=0;
	W_count=0;
 }
return 0;
}


