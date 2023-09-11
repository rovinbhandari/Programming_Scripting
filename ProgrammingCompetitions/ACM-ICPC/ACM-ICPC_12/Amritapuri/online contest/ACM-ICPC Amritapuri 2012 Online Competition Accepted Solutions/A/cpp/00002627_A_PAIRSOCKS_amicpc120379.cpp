#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
long long A[85];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
       char val[100];
        map<char,int> values;
        values['R']=2;
        values['B']=2;
        values['G']=2;
        values['W']=2;
        scanf("%s",&val);
        int len=strlen(val);
        for(int i=0;i<len;i++)
            values[val[i]]+=1;
        //cout<<values['R']<<" "<<values['G']<<endl;
        if(values['R']%2==0 && values['G']%2==0 && values['B']%2==0 && values['W']%2==0)
            printf("YES\n");
        else
            printf("NO\n");

    }
	return 0;
}
