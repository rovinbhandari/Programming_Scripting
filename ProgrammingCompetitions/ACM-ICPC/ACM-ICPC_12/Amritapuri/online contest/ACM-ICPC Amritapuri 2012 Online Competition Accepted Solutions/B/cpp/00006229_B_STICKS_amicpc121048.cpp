#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        int N,M, answer = 0;
        long long int a,b,c,l;
        cin >> N >> M;
        int i,j;
        int n[N];
        for(i=0;i<N;i++) {
            cin >> n[i];
        }
        long long int diagonal = 0;
        for(i=0;i<M;i++) {
            cin>>a>>b>>c;
            double d = sqrt(a*a + b*b + c*c);
            long long int dd = static_cast<long long int>(d);
            if(dd > diagonal) {
                diagonal = dd;
            }
        }
        for(i=0;i<N;i++) {
            if(n[i]<=diagonal) {
                answer++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}

