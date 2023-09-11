#include<iostream>
#include<algorithm>
using namespace std;

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              int n,L,H;
              cin>>n>>L>>H;
              int A[n];
              for(int i=0;i<n;i++)
              cin>>A[i];
              sort(A,A+n);
           
       int l, r,count=0;
 
         for(int i=0; i<n-2;i++){
              //   cout<<A[i];
        l = i + 1; 
        r = n-1;
     //   cout<<"   "<<l<<"  "<<r<<endl;
        while (l<r)
        {
          //  cout<<A[i]<<"  jj "<<A[l]<<"  "<<A[r]<<endl;
            if (A[i] + A[l] + A[r]<=H)
                {
                     count+=(r-l);
                     l++;
        //             cout<<"ofmfdfm    "<<count<<endl;
                }
            else
                r--;
        }
    }    
      // cout<<" jmjg"<<count<<endl;
       for(int i=0; i<n-2;i++){
        l = i + 1; 
        r = n-1;
        while (l<r)
        {
            
            if (A[i] + A[l] + A[r]<L)
                {
                     count-=(r-l);
                     l++;
                }
            else
                r--;
        }
 }
    cout<<count<<endl; 
}
return 0;
} 
