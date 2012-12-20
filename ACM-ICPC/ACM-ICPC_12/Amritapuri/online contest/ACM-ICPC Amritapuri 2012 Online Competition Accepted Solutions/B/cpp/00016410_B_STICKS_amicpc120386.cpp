#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    double max = 0.0;
    // t = 10;
    
    for (int i = 0; i < t; ++i) {
        unsigned long long int n, m;
        scanf("%lld", &n);
        scanf("%lld", &m);
        // n = m = 50000;
    
        unsigned long long int l[n];
        double dim[m][4];
        
        for (unsigned int j = 0; j < n; ++j) {
            scanf("%lld", &l[j]);
        }
        
        max = 0.0;
        double max1;
        for (unsigned int j = 0; j < m; ++j) {
            dim[j][3] = 0;
            for (int k = 0; k < 3; ++k) {
                scanf("%lf", &dim[j][k]);
                dim[j][3] += dim[j][k]*dim[j][k];
            }
            dim[j][3] = pow(dim[j][3], 0.5);
            
            max1 = dim[j][0];
            for(int k = 1; k < 4; ++k) {
                    if (dim[j][k] > max1) max1 = dim[j][k];
            }
            if(max1 > max) max = max1;
        }
        int ctr = 0;
        for(int i = 0; i < n; ++i) 
                if(l[i] <= max) ++ctr;
        printf("%d\n", ctr);
    }
            
            
    //system("pause");
    return 0;
}
