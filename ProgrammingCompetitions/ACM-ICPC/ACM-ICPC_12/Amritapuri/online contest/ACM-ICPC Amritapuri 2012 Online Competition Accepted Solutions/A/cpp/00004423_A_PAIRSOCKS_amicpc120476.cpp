#include <iostream>
#include <string>

using namespace std;


int main(){

    //r -> 0, g -> 1, b -> 2, w -> 3
    int T;
    string str;
    bool flag = true;
    short A[] =  {0,0,0,0};

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> str;
        flag = true;
        for(int j = 0; j < str.length(); j++){
            if(str[j] == 'R'){
                A[0] = (A[0] + 1) % 2;
                continue;
            }
            if(str[j] == 'G'){
                A[1] = (A[1] + 1) % 2;
                continue;
            } 
            if(str[j] == 'B'){
                A[2] = (A[2] + 1) % 2;
                continue;
            }
            if(str[j] == 'W'){
                A[3] = (A[3] + 1) % 2;
                continue;
            }
        }
        for(int j = 0; j <=3; j++){
            if(A[j]){
                flag = false;
            }
            A[j] = 0;
        }
        if(flag) 
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
