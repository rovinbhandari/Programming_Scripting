#include<cstdio>
#include<vector>
using namespace std;

long long int exp_mod(int exponent){
	long long int result = 1;
	long long int base = 2;
	long long int m = 1000000007;
	while (exponent > 0){
		if (exponent % 2){
			result *= base;
			if(result > m) result %= m;
		}
		exponent >>= 1;
		base *= base;
		if(base > m) base %= m;
	}
	return result;
}

int main(){
	int t;	
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<vector<int> > graph(n);
		int i, j, k, q;
		for(i = 0; i < n; ++i){
			scanf("%d",&k);
			for(j = 0; j < k; j++){
				scanf("%d", &q);
				graph[i].push_back(q);
				graph[q].push_back(i);
			}
		}
		int visited[20001] = {0};
		int count = 0, flag = 0;
		for(int v = 0; v < n; v++){
			if(visited[v] != 0) continue;
			++count;
			int color = 1;
			visited[v] = 1;			
			int queue[20001];
			queue[0] = v;
			int rear = 1, front = 0;
			while(front < rear)
			{
				int k = queue [front++];
				color = (visited[k] & 1);
				for(j = 0; j < graph[k].size(); j++){
					int r = graph[k][j];
					if(visited[r] == visited[k]){
						flag = 1;
						break;
					}
					if(visited[r] != 0) continue;
					visited[r] = color + 1;
					queue[rear++] = r;
				}
				if(flag)
					break;
			}
			if(flag)
				break;		
		}
		if(flag)
			printf("0\n");
		else
			printf("%lld\n", exp_mod(count));
	}
	return 0;
}
