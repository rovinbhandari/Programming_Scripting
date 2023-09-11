/*
A tree is a acyclic ,connected graph.
*/

#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;
int MOD=1000000007;
bool cycle_detected;
stack<int> myStack;
int parent[20002];
int color[20002];
int region[20002];
int g_time;
int visited;
bool disconnected=false;
struct node
{
	int vert_no;
	struct node *next;	
};
int DFS_Visit(struct node *graph[],int,int[],int[],int[]);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	long long int sol[test_cases],count;
	int no_vertices,no_edges;
	for(int i=0;i<test_cases;i++)
	{
		//bool graph[100][100];
		//cin>>no_vertices>>no_edges;
		count=1;
		scanf("%d",&no_vertices);
		struct node *head[no_vertices];
		struct node *tail[no_vertices];
		int v_1;
		for(int j=0;j<no_vertices;j++)
		{
			head[j]=new(struct node);
			head[j]->vert_no=j;
			head[j]->next=NULL;
			tail[j]=head[j];
		}
		for(int j=0;j<no_vertices;j++)
		{
			scanf("%d",&no_edges);
			for(int k=0;k<no_edges;k++)
			{
				//cin>>v_1>>v_2;
				scanf("%d",&v_1);
				struct node *newnode=new(struct node);
				newnode->vert_no=v_1;
				newnode->next=NULL;
				tail[j]->next=newnode;
				tail[j]=newnode;
				struct node *nnode=new(struct node);
				nnode->vert_no=j;
				nnode->next=NULL;
				tail[v_1]->next=nnode;
				tail[v_1]=nnode;
			}
		}
	//	for(int i=0;i<100;i++)
	//	{
	//		for(int j=0;j<100;j++)
	//		{
	//			graph[i][j]=0;
	//		}
	//	}
		for(int j=0;j<no_vertices;j++)
		{
			color[j]=0;
			region[j] = -1;
	//		for(int j=0;j<no_vertices;j++)
	//		{
	//			cin>>graph[i][j];
	//		}
		}
		int ret;
		for(int j=0;j<no_vertices;j++)
		{
			if(color[j]==0)
			{
				myStack.push(j);
				color[j]=1;
				parent[j]=-1;
				region[j] = 1;//mamrita;
				ret = DFS_Visit(head,no_vertices,color,parent,region);
				if(ret==-1)
				{	
					count = 0;
					break;
				}
				else if(ret ==1)
				{
					count = ((count%MOD)*2)%MOD;
				}
			}
		}
	//	for(int i=0;i<no_vertices;i++)
	//	{
	//		cout<<start_time[i]<<":"<<finish_time[i]<<endl;
	//	}
//		if(cycle_detected)
//		{
//			cout<<"NO";
//		}
//		else
//		{
//			if(!disconnected)
//			{
//				cout<<"YES";
//			}
//			else
//			{
//				cout<<"NO";
//			}
//		}
	
		for(int j=0;j<no_vertices;j++)
		{
			struct node *current=head[j];
			struct node *temp;
			while(current!=NULL)
			{
				temp=current;
				current=current->next;
				delete(temp);
			}
		}
		sol[i] = count;
	}
	for(int i=0;i<test_cases;i++)
	{
		printf("%lld\n",sol[i]);
	}
	
}
int DFS_Visit(struct node *graph[],int no_vertices,int color[],int parent[],int region[])
{
	int start_vertex=myStack.top();
	int ret;
	myStack.pop();
	visited++;
//	cout<<start_vertex<<" ";
	struct node *cur=graph[start_vertex];
	while((cur=cur->next)!=NULL)
	{
		if(!color[cur->vert_no])
		{
			myStack.push(cur->vert_no);
			color[cur->vert_no]=1;
			parent[cur->vert_no]=start_vertex;
			region[cur->vert_no] = 1-region[start_vertex];
			ret = DFS_Visit(graph,no_vertices,color,parent,region);
			if(ret==-1)
				return -1;
		}
		else if(color[cur->vert_no])
		{
			//if(parent[start_vertex]!=(cur->vert_no))
			//{
//			//	cout<<"Cycle Detected"<<endl;
//		//		cout<<start_vertex<<":"<<cur->vert_no-1<<endl;
				//cycle_detected=true;
				//return;
				
			//}
			if(region[cur->vert_no]==region[start_vertex])
			{
				return -1;
			}
		}
	}
//	for(int i=0;i<no_vertices;i++)
//	{
//		if(graph[start_vertex][i]==1 && !color[i])
//		{
//			myStack.push(i);
//			color[i]=1;
//			parent[i]=start_vertex;
//			DFS_Visit(graph,no_vertices,color,start_time,finish_time,parent);
//		}
//		else if(graph[start_vertex][i]==1 && color[i])
//		{
//			if(parent[start_vertex]!=i)
//			{
//				cout<<"Cycle Detected"<<endl;
//				cout<<start_vertex<<":"<<i<<endl;
//			}
//			
//		}
//	}
	color[start_vertex]=2;
	return 1;
}
