#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    int i;
    cin>>t;
    while(t--){
        int n,m;
        cin >> n;
        cin >> m;
        long long int a[n];
        for(i=0;i<n;i++) cin>>a[i];
        long long int b[m][3];
        for(i=0;i<m;i++) cin>>b[i][0]>>b[i][1]>>b[i][2];
        
        long long int maxval=1;
        long long int diag = 0;
        for(i=0;i<m;i++) {
            diag = ((b[i][0]*b[i][0])+(b[i][1]*b[i][1])+(b[i][2]*b[i][2]));
            if(diag > maxval){
                maxval = diag;
            }
        }
        int cnt=0;
        for(i=0;i<n;i++){
            long long int sq=a[i]*a[i]; 
            if(sq <= maxval) cnt++;
        }
        cout<<cnt<<endl;
    }
}
