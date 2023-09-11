/* 
 * File:   main.cpp
 * Author: SRINIVASAN
 *
 * Created on November 4, 2012, 8:42 AM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

using namespace std;

int main(int argc, char** argv)
{
    int T, i, r, g, b, w;
    char s[50];
    
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%s", s);
        
        r = g = b = w = 0;
        
        for(i = 0; s[i] != NULL; i++)
        {
            if(s[i] == 'R')
                r++;
            if(s[i] == 'B')
                b++;
            if(s[i] == 'G')
                g++;
            if(s[i] == 'W')
                w++;
        }
        
        if((r % 2 == 0) && (g % 2 == 0) && (b % 2 == 0) && (w % 2 == 0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}

