# include <iostream>
# include <cstdio>
# include <cstring>
# include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    getchar();
    for (int i = 0; i < t; i++){
             char a[100];
             map<char,int> m;
             map<char,int> :: iterator it;
             gets(a);
             for (int j = 0; j < strlen(a);j++){
                      if(m.count(a[j])){
                                        m[a[j]]++;
                      } else {
                             m.insert(pair<char,int>(a[j],1));
                      }
             }
             int f = 0;
             for (it = m.begin();it != m.end();it++){
                 if((*it).second % 2 != 0){
                                   f = 1;
                                  break;
                 }
             }
             if(f == 0){
                  cout << "YES" << endl;
             } else {
                    cout << "NO" << endl;
             }
    }
    
    //int op;
    //cin >> op;
}
