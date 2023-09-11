/* Enter your code here. Read input from STDIN. Print output to STDOUT */


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;

int main()
{
  int cases;
    scanf("%d",&cases);
    for(int i=1;i<=cases;i++){
    string out = "YES";
        string input;
        int a[4];
         for(int k=0;k<4;k++){
                a[k] = 0;
                }
       cin >> input;
       // scanf("%s",input.c_str());
        int temp = input.length()-1;
      //  printf("%d -> %s ->",temp,input.c_str());
         if(temp%2 != 0){
            for(int j=0;j<input.length();j++){
                if(input[j] == 'R'){
                    a[0]++;continue;}
                if(input[j] == 'G'){
                    a[1]++;continue;}
                if(input[j] == 'B'){
                    a[2]++;continue;}
                if(input[j] == 'W'){
                    a[3]++;continue;}
            }    
            for(int k=0;k<4;k++){
                if(a[k]%2 != 0){
                 out = "NO";
                    break;
                }
            }
        }
        else out = "NO";
    cout << out << endl;
    }
}
