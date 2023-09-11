/* Author: Kuldeep
 * Email: kuldeep5534@gmail.com
 *  :: pairOfSocks.cpp
 * Date: 04.11.2012 09:48:04 IST
 * Description: 
 */
 
#include <iostream>
#include <string>

using namespace std;

bool pairOfSocks(string str){
	int R,G,B,W;
	R = G = B = W = 0;
	int i = 0;
	while (str[i]){
		if (str[i] == 'R'){
			R++;
			R%=2;
		}else if (str[i] == 'G'){
			G++;
			G%=2;
		}else if (str[i] == 'B'){
			B++;
			B%=2;
		}else{
			W++;
			W%=2;
		}
		i++;
	}
	
	if (R == 0 && G == 0 && B == 0 && W == 0){
		return true;
	}else{
		return false;
	}
}
	

int main(int argc,char ** argv)
{
	int numberOfInputs;
	cin>>numberOfInputs;
	string input;
	for (int i = 0; i < numberOfInputs; i++){
		cin>>input;
		if (pairOfSocks(input)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
