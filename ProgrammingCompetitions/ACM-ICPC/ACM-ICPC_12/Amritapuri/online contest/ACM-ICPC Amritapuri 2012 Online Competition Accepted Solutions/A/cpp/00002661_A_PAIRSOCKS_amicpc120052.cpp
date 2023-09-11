#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cctype>
#include<fstream>

typedef long long LL;

#define FOR(i, a, b) 	for(LL i=a;i<b;i++)
#define REP(i, a) 	FOR(i, 0, a)
#define RFOR(i, a, b) 	for(LL i=a-1;i>=b;i--)
#define RREP(i, a) 	RFOR(i, a, 0)
#define PB(x) 		push_back(x)
#define PP() 		pop_back()
#define SZ 		size()
#define LEN 		length()
#define BG 		begin()
#define ED 		end()

using namespace std;

int main(int argc, char** argv)
{

        LL n;
        LL s[4];
        string str;

        scanf("%lld", &n);
        cin.ignore();

        REP(z, n){

            REP(i, 4){
                    s[i] = 0;
            }

            getline(cin, str);

            REP(i, str.LEN){
                if(str[i] == 'R')
                    s[0] += 1;
                else if(str[i] == 'G')
                    s[1] += 1;
                else if(str[i] == 'B')
                    s[2] += 1;
                else if(str[i] == 'W')
                    s[3] += 1;
            }

            bool pairs = true;
            REP(i, 4){
                if(s[i] % 2 != 0){
                    pairs = false;
                    break;
                }
            }

            if(pairs)
                printf("YES\n");
            else
                printf("NO\n");
        }
	return 0;
}
