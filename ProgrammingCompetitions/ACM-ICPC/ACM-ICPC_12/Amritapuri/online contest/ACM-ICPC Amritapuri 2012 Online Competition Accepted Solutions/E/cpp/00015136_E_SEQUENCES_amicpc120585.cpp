#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;

struct triplet
{
	
	int zero_zero;
	int zero_one;
	int one_one;
	int lower;
	int upper;
	triplet()
	{
		//zero_zero = a;
		//zero_one = b;
		//one_one = c;
	}
};


triplet combine(triplet a,triplet b)
{
	triplet answer;
	answer.zero_zero = a.zero_zero+b.zero_zero;
	answer.zero_one = max(max(a.zero_zero+b.zero_one,a.zero_one+b.one_one),a.zero_zero+b.one_one);
	answer.one_one = a.one_one+b.one_one;
	answer.lower = min(a.lower,b.lower);
	answer.upper = max(a.upper,b.upper);
	return answer;
}

triplet f(int lower,int upper,triplet* hp,int size_of_heap,int root)
{
	//cout<<"Lower: "<<lower<<"\tUpper: "<<upper<<"\tRoot: "<<root<<"\tL: "<<hp[root].lower<<"\tU: "<<hp[root].upper<<endl;
	triplet answer;
	int i  = (hp[root].lower+hp[root].upper)/2;
	if(lower == hp[root].lower && upper==hp[root].upper)
	{
		answer = hp[root];
	}
	else if(lower<=i && upper>i)
	{
		answer = combine(f(lower,i,hp,size_of_heap,root*2+1),f(i+1,upper,hp,size_of_heap,root*2+2));
	}
	else if(lower>i)
	{
		answer = f(lower,upper,hp,size_of_heap,root*2+2);
	}
	else if(upper<=i)
	{
		answer = f(lower,upper,hp,size_of_heap,root*2+1);
	}
	
	return answer;
}


int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int N;
		cin>>N;
		int* seq = new int[N];
		char input;
		for(int j=0;j<N;j++)
		{
			cin>>input;
			seq[j] = input-48;
		}
		//form the tree
		int h = (int)((log((double)N))/(log(2.0)))+1;
		int sz = pow(2,h);
		triplet* eval_heap = new triplet[2*sz-1];
		triplet temp;
		for(int j=0;j<sz;j++)
		{
			if(j<N)
			{
				if(seq[j]==0)
				{
					temp.zero_zero = 1;
					temp.zero_one = 0;
					temp.one_one = 0;
					temp.lower = j+sz-1;
					temp.upper = j+sz-1;
					eval_heap[sz+j-1] = temp;
				}
				else if(seq[j]==1)
				{
					temp.zero_zero = 0;
					temp.zero_one = 0;
					temp.one_one = 1;
					temp.lower = j+sz-1;
					temp.upper = j+sz-1;
					eval_heap[sz+j-1] = temp;
				}
			}
			else
			{
				temp.zero_zero = 0;
				temp.zero_one = 0;
				temp.one_one = 0;
				temp.lower = j+sz-1;
				temp.upper = j+sz-1;
				eval_heap[sz+j-1] = temp;
			}
		}
		for(int j=sz-2;j>=0;j--)
		{
			temp = combine(eval_heap[2*j+1],eval_heap[2*j+2]);
			eval_heap[j] = temp;
		}
		
		//cout<<"Completed taking input"<<endl;
		
		
		int Q;
		cin>>Q;
		triplet query;
		for(int j=0;j<Q;j++)
		{
			int a,b;
			cin>>a>>b;
			//answer query
			query = f(a+sz-2,b+sz-2,eval_heap,2*sz-1,0);
			int ans = max(max(query.zero_zero,query.zero_one),query.one_one);
			cout<<ans<<endl;			
		}
	}
	return 0;
}







	/*triplet t1 = *(new triplet(4,6,4));
	triplet t2 = *(new triplet(2,4,3));
	t1 = combine(t1,t2);
	cout<<t1.zero_zero<<"\t"<<t1.zero_one<<endl;*/
