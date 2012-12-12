#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main(){
	int t;
		char a[10000];
	scanf("%d", &t);
	while(t--)
	{
		map<char, int> h;
		scanf("%s", a);
		for(int i=0;a[i]!='\0';i++)
		{
			h[a[i]]++;
		}
		if(h['R']%2 ||h['W']%2 ||h['B']%2 ||h['G']%2)
		{
			printf("NO\n");
		}
		else
			printf("YES\n");
	}
	return 0;
}
