#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    long long t,m,n;
    long long box[3];
    double stick[50000]; 
    cin>>t;
    long long total[t];
    for(int j=0;j<t;j++)
    {
        total[j] = 0;
        cin>>n>>m;
        //stick = (float*) malloc(n * sizeof(float));
        double max_diagonal=0;
        double diagonal;
        
        for(int i=0;i<n;i++) {
            cin>>stick[i];
        }
        
        for(int i=0;i<m;i++) {
            cin>>box[0]>>box[1]>>box[2];
            diagonal = (box[0] * box[0]) + (box[1] * box[1]) + (box[2] * box[2]);
            if(diagonal > max_diagonal) 
                max_diagonal = diagonal;
        }
        for(int i=0;i<n;i++) {
            if((stick[i] * stick[i]) <= max_diagonal) 
                total[j]++;
        }
        //free(stick);
    }
    for(int i=0;i<t;i++)
    	cout<<total[i]<<endl;
}
