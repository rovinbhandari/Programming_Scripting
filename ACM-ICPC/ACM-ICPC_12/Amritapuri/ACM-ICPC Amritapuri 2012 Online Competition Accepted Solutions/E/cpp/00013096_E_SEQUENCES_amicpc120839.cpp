#include<stdio.h>
#include<stdlib.h>
#include<string>
	using namespace std;
#include<math.h>

template<class T>
class SegmentTree
	{
	int *A,size;
	public:
	SegmentTree(int N)
 		{
		int x = (int)(ceil(log2(N)))+1;
          	size = 2*(int)pow(2,x);
          	A = new int[size];
          	for(int i=0;i<N;i++)
			A[i]=-1;
     		}
     	void initialize(int node, int start,int end, T *array)
     		{
		if (start==end)
          		A[node] = start;
          	else
          		{
          		int mid = (start+end)/2;
          		initialize(2*node,start,mid,array);
 			initialize(2*node+1,mid+1,end,array);
              		if (array[A[2*node]]>=array[A[2*node+1]])
                 		A[node] = A[2 * node];
              		else
                  		A[node] = A[2 * node + 1];
          		}
     		}
     	int query(int node, int start,int end, int i, int j, T *array)
     		{
        	int id1,id2;
         	if (i>end || j<start)
            		return -1;

        	if (start>=i && end<=j)
            		return A[node];

         	int mid = (start+end)/2;
       		id1 = query(2*node,start,mid,i,j,array);
        	id2 = query(2*node+1,mid+1,end,i,j,array);

        	if (id1==-1)
            		return id2;
         	if (id2==-1)
            		return id1;

         	if (array[id1]>=array[id2])
            		return id1;
         	else
             		return id2;
     		}
	};


void print(int *A, int N)
	{
	printf("[");
	for(int i=0;i<N;i++)
		printf("%d ",A[i]);
	printf("]\n");
	}
int main()
	{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
		{
		int N;
		scanf("%d",&N);
		char *S=(char *)malloc(N*sizeof(char));
		scanf("%s",S);
		
		int *Z=(int *)malloc(N*sizeof(int));			//number of zeros <i
		int *O=(int *)malloc(N*sizeof(int));			//number of ones >i
		O[N-1]=0;
		if(S[0]=='0')
			Z[0]=0;
		for(int i=1;i<N;i++)
			{
			if(S[i-1]=='0')
				Z[i]=1+Z[i-1];
			else
				Z[i]=Z[i-1];
			}
		for(int i=N-1;i>=1;i--)
			{
			if(S[i]=='1')
				O[i-1]=1+O[i];
			else
				O[i-1]=O[i];
			}
		int *Sum=(int *)malloc(N*sizeof(int));			//number of ones >i
		for(int i=0;i<N;i++)
			Sum[i]=Z[i]+O[i];
		//print(Z,N);
		//print(O,N);	
				
		SegmentTree<int> s(N);
		s.initialize(1,0,N-1,Sum);
		
		int Q;
		scanf("%d",&Q);
		for(int q=0;q<Q;q++)
			{
			int a,b;
			scanf("%d %d",&a,&b);
			a--;b--;
			if(a==b)
				{
				printf("1\n");
				continue;
				}
			//printf("for range: (%d, %d) \n",a,b);
			int zeros_a=Z[a];
			int ones_b=O[b];
			int query=Sum[s.query(1,0,N-1,a,b,Sum)];
			//printf("zeros_a= %d, ones_b= %d, query= %d\n: \n",zeros_a,ones_b,query);
			printf("%d\n",(query-zeros_a-ones_b)+1);
			}
		free(S);
		free(Z);
		free(O);
		free(Sum);	
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
