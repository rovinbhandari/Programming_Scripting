#include<iostream>
#include <queue>
#include<vector>
using namespace std;

int main()
{
	//input part
	int size,temp,i,j,k,T,n,flag,count=0;
	long long int L,H,sum;
	vector<int> v;
	//cout<<"enter number of values to be stored ";
	cin>>T;
	for(n=0;n<T;n++){       
				count=0;
				flag=0;
				cin>>size;
				cin>>L;
				cin>>H;
				long long int a[size];
				long long int b[size];
				for( i=0;i<size;i++)
					cin>>b[i];
	
				//sorting begins
				priority_queue<int> second (b,b+size);
				for( i=0;i<size;i++){
					a[i]=second.top();
					second.pop();
					}
	
				
	
				for(i=0;i<size;i++){
				if(a[i]>H)continue;
				for(j=i+1;j<size ;j++){
				        if(a[i]+a[j]>H)continue;
				 	for(k=j+1;k<size;k++){
				 		
				 		sum=a[i]+a[j]+a[k];
				 		
				 		if(sum<L) {break;}
				 		else if(sum>=L && sum<=H)count++;
				 	}
				 }
			}

			v.push_back(count);
	}
	 vector<int>::iterator it;
	 for ( it=v.begin() ; it < v.end(); it++ )
              cout << *it<<endl;
	return 0;
}
		
