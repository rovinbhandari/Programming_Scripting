// Authors : The_Iterators
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int r = 0;
        int g = 0;
        int b = 0;
        int w = 0;
        string S;
        cin>>S;
        for(int i=0;i<S.size();i++) {
            if(S[i] == 'R')
                r++;
            else if(S[i] == 'G')
                g++;
            else if(S[i] == 'B')
                b++;
            else if(S[i] == 'W')
                w++;
        }
        if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
	return 0;
}
