#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define MAXIM 1000000007

using namespace std;

int N;
long long A[1001];

bool range(int a,int b,int c){
    return min(a,b)<=c && max(b,a)>=c;
}
int binsearch(int key,int t,int start){
    int end = N;
    
    while(start<end){
        int mid = (start+end)/2;
        int val = A[mid];
        
        if(key < val){
            end = mid;
        }
        else if(key > val){
            start = mid+1;
        }
        else{
            break;
        }
    }
    return (start+end)/2;
}



int _ret(int low,int high,int j1){
    
    int h = binsearch(high,1,j1);
    int l = binsearch(low,0,j1);
    if(A[l]!=low && h<N && A[h]==high) h++;
    else if(A[l] == low && h<N && A[h] == high) h++;
    return max(0,h-l);   
}
    
    

int main(){
    int T;
    long long L,H;
    cin>>T;
    
    while(T--){
        cin>>N>>L>>H;
        
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        sort(A,A+N);
        int count = 0;


                
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                int pres = A[i]+A[j];
                if(pres <= H){
                    ////cout<<pres<<endl;
                    int ukey = H-pres;
                    int lkey = L-pres;
                    //cout<<lkey<<" "<<ukey<<" "<<_ret(lkey,ukey,j+1)<<endl;
                    int p=0;
                    /*
                    if(range(ukey,lkey,A[i])) p++;
                    if(range(ukey,lkey,A[j])) p++;
                    */
                    count+= max(0,_ret(lkey,ukey,j+1));
                    //cout<<count<<endl;
                }
                else{
                    break;
                }
            }
        }
        
        cout<<count<<endl;
    }
    return 0;
}
