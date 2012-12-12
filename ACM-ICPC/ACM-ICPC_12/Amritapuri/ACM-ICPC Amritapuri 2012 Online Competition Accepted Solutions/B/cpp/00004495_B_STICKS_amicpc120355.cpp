//
//  template.cpp
//  ACM
//
//  Created by Krishna Pillutla on 04/11/12.
//  Copyright (c) 2012 pillutla.krishna@gmail.com. All rights reserved.
//

#include <cstdio>
#include <cmath>


int main(){
    int num;
    scanf("%d", &num);
    
    int n, m, i, j, a, b, c, total;
    int *l;
    while (num > 0) {
        scanf("%d %d", &n, &m);
        l = new int[n];
        total = 0;
        
        for (i = 0; i < n - 1; ++i) {
            scanf("%d", &l[i]);
        }
        scanf("%d\n", &l[n - 1]);
        int max = 0;
        while (m > 0){
            scanf("%d %d %d", &a,&b, &c);
            int d = (int) sqrt( (float) a*a + b*b + c*c);
            if (d > max) max = d;
            
            --m;
        }
        for (i = 0; i < n; ++i) {
            if (max >= l[i]) ++total;
        }
        
        printf("%d\n", total);
        delete[] l;
        
        --num;
    }
}
