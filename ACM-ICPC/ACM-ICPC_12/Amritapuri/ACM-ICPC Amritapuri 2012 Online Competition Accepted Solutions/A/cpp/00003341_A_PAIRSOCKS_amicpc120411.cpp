#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()  {
    int T, arr[5], i;
    char str[100];
    bool flag = true;
    //freopen("input.txt", "r", stdin);
    cin >> T;
    while(T--)  {
        scanf("%s", str);
        for(i=0; i<5; i++) arr[i] = 0;
        for(i=0; str[i] != '\0'; i++)   {
            switch(str[i])  {
                case 'R': arr[0]++; break;
                case 'G': arr[1]++; break;
                case 'B': arr[2]++; break;
                case 'W': arr[3]++; break;
            }
        }
        flag = true;
        for(i=0; i<4; i++)
            if(arr[i] & 1)  {
                printf("NO\n");
                flag = false; break;
            }
        if(flag)
            printf("YES\n");
    }
    return 0;
}
