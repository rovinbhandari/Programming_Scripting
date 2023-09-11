#include<iostream>
#include<string.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    int outputArray[T];
    string sequence;
    int checkArray[4];
    int noInserted = 1;
    while (noInserted<=T) {
        cin>>sequence;
        for(int i=0;i<4;i++){
            checkArray[i]=0;
        }
        for (int i=0; i<sequence.length(); i++) {
            if(sequence[i]=='R') {checkArray[0] = not checkArray[0];}
            else if(sequence[i]=='G') {checkArray[1] = not checkArray[1];}
            else if(sequence[i]=='B') {checkArray[2] = not checkArray[2];}
            else if(sequence[i]=='W') {checkArray[3] = not checkArray[3];}
        }
        if (checkArray[0]== 0 && checkArray[1] == 0 && checkArray[2] == 0 && checkArray[3] == 0 ) {
            outputArray[noInserted-1]=1;
        }
        else{
            outputArray[noInserted-1]=0;
        }
       /* for(int i=0;i<4;i++){
            cout<<checkArray[i]<<endl;
        }*/
        noInserted++;
    }
    for (int i=0; i<T; i++) {
        if (outputArray[i]==0) {
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
}