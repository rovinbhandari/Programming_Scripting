#include<iostream>
using namespace std;
class A1 {

        public:

                int upper;

                int lower;

                A1( int i ) : lower( i ), upper( lower+1 ) { };

};


int main(){

        A1 a(5);

        cout << a.lower << " " << a.upper << endl;

return 0;

}
