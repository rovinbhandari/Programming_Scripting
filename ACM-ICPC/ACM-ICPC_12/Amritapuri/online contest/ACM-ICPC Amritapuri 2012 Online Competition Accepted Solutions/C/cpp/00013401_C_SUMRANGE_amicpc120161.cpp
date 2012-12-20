#include <cstdio>
#include <queue>

using namespace std;

// class list{
// public:
// 	list(int m=0){
// 		max_limit=m;
// 		head = new node();
// 	}
// 	void insert(int d){
// 		for( node* itr = head; itr->next&&itr) {
			
// 		}
// 	}
// private:
// 	int max_limit;
// 	class node {
// 	public:
// 		node(node *n=NULL, int d=0):data(d), next(n);
// 		int data;
// 		node *next;
// 	};
// 	node *head;
// };

int main() {
	int t,n,l,h,i,j,k,temp;
	int max_index;
	scanf("%d", &t);
	for(int itr=0; itr<t; itr++) {
		priority_queue<int> q;
		scanf("%d %d %d", &n, &l, &h);
		int temp_size=0;
		for(int itr1=0; itr1<n; itr1++) {
			scanf("%d", &temp);
			if(temp<h) {
				q.push(temp);
				temp_size++;
			}
		}
		const int size = temp_size;
		int a[size];
		for(int itr1=0; itr1<size; itr1++) {
			a[itr1] = q.top();
			// printf("a: %d \n", a[itr1]);
			q.pop();
		}
		// printf("l:%d h:%d\n", l, h);
		int count = 0, sum=0;
		for( int b=0; b<size; b++) {
			// int c=b+1, d=size-1;
			// int suml = l-a[b], sumh =h-a;
			// while(c<=d) {

			// }
			for( int c=b+1; c<size; c++) {
				if((a[b]+a[c])>=h) {
					continue;
				}
				for ( int d=c+1; d<size; d++) {
					sum = a[b]+a[c]+a[d];
					// printf("%d %d %d b:%d c:%d d:%d sum:%d\n", a[b], a[c], a[d], b, c, d, sum);
					if(sum<=h && sum>=l) {
						// printf("^ yes\n");
						count++;
					}
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}