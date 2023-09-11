#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdlib>

using namespace std;

long long int m = (long long int)1e9 + 7;
vector <long long int> v[20000];
int color[20000];

long long int exp_mod( long long int a, long long int b )          // O(log b)
{
    long long int ans = 1, y = a;
    
    while ( b > 0 ) {
          if ( b & 1 ) {
               ans = ( ans * y ) % m;
          }
          y = (y * y) % m;
          
          b >>= 1;
    }
    ans = ans % m;
    
    return(ans);                
}

int check(int n){
       int b, i, j;
       int visited[20000];
       stack <int> s;
       memset(visited, 0, sizeof visited);
       for(int i = 0; i < n; i++){
               if(visited[i] == 0){
                    visited[i] = 1;
                    s.push(i);
                    color[i] = 1;
                    while(!s.empty()){
                            b = s.top();
                            s.pop();
                            for(j = 0; j < v[b].size(); j++){
                                  if(visited[v[b][j]] == 0){
                                       visited[v[b][j]] = 1;
                                       s.push(v[b][j]);
                                       if(color[b] == 1)
                                           color[v[b][j]] = 0;
                                       else
                                           color[v[b][j]] = 1;
                                  }
                                  else if(visited[v[b][j]] == 1 && color[b] == color[v[b][j]])
                                       return true;
                            }
                    }
               }
       }
       return false;
}

int main(){
    long long int i, j, k, n, t, a, b, dis_comp, sing, cycle;
    cin >> t;
    stack <long long int> s;
    int visited[20000];
    for(i = 0; i < t; i++){
          cin >> n;
          memset(visited, 0, sizeof visited);
          dis_comp = 0;
          sing = 0;
          for(j = 0; j < n; j++){
                cin >> a;
                for(k = 0; k < a; k++){
                      cin >> b;
                      v[j].push_back(b);
                      v[b].push_back(j);    
                }
          }
          if(check(n)){
                       cout << 0 << endl;
                       for(j = 0; j < 20000; j++)
                             v[j].clear();
                       continue;
          }
          for(j = 0; j < n; j++){
                if(visited[j] == 0){
                     s.push(j);
                     visited[j] = 1;
                     dis_comp++;
                     while(!s.empty()){
                          b = s.top();
                          s.pop();
                          if(v[b].size() == 0)
                             sing++;
                          for(k = 0; k < v[b].size(); k++){
                                if(visited[v[b][k]] == 0){
                                    s.push(v[b][k]);
                                    visited[v[b][k]] = 1;
                             }
                         }
                     }
                }
          }
          
          dis_comp = dis_comp - sing;
          
          cout << (exp_mod(2, dis_comp)*exp_mod(2, sing))%m << endl;
          
          for(j = 0; j < 20000; j++)
                v[j].clear();
    }
    //system("pause");
    return 0;
}
/*
2
9
0
2 2 4
0
1 5
1 5
0
1 8
1 8
0
*/
