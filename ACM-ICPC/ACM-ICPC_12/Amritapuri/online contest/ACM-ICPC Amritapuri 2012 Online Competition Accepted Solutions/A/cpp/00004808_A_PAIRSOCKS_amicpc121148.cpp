#include<iostream>
#include <cstdio>
#include<string>
#include<algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
	vector<int> vec(4);
	scanf("%d",&T);
	while(T-- > 0) {
	    for(int i=0;i<4;i++)
            vec[i] = 0;
		string str;
		bool flag = true;
		cin >> str;
		for (int i=0;i<str.length();i++) {
			char ch = str[i];
            //printf("(ch = %c)",ch);
			switch(ch) {
				case 'R':
					vec[0] += 1;
					break;
				case 'G':
					vec[1] += 1;
					break;
				case 'B':
					vec[2] += 1;
					break;
				case 'W':
					vec[3] += 1;
					break;
			}
		}
		for(int i=0;i<4;i++) {
		    //printf("%d ",vec[i]);
			if(vec[i] % 2 != 0) {
				flag = false;
				break;
			}
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
