//
//  main.cpp
//  ACM_ICPC
//
//  Created by Guna Prasaad on 04/11/12.
//  Copyright (c) 2012 Guna Prasaad. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[])
{
    int N = 0;
    string temp = "";
    cin>>N;
    getchar(); //for entering the next line
    for(int i= 0; i < N; i++) {
        bool R = true;
        bool B = true;
        bool W = true;
        bool G = true;
        char ch =getchar();
        while(ch != '\n') {
            if(ch == 'R') {
                R = !R;
            } else if(ch == 'B') {
                B = !B;
            } else if(ch == 'W') {
                W = !W;
            } else if(ch == 'G') {
                G = !G;
            }
        ch = getchar(); 
        }
        temp.append((G && R && B && W) ? "YES\n":"NO\n");
        if (i == (N-1)){
        	break;
        }
        //ch = getchar(); //for entering the next line
    }
    cout << temp;
}

