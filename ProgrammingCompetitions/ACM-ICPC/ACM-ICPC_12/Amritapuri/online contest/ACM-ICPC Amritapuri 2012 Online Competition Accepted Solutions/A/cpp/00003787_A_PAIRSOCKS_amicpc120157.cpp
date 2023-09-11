// flying_dutchman


#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int r, g, b ,w;
        r = g = b = w = 0;
        string str;
        cin >> str;
        int len = str.length();
        for (int i=0; i<len; i++){
            switch (str[i]){
                case 'R':r++;break;
                case 'G':g++;break;
                case 'B':b++;break;
                case 'W':w++;break;
            }
        }
        if ( (r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
