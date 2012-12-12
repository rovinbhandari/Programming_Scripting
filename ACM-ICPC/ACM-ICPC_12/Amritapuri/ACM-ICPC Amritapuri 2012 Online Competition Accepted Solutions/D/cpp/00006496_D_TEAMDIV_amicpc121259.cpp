#include<iostream>
#include<list>
#include<queue>
#include<stack>
#include<utility>
#include<vector>
#define SIZE 1000000007

using namespace std;
struct node
{
  int parent,index;
  int visited;
  int color;
};

list <int> adj[100002];
node vertex[100002];

main()
{
  long long int a,b,w,n,m,i,t;
  bool check;
  bool bfs(node&);
  int dfs(node&);
  cin>>t;
  while(t--){
    
    cin>>n;
    
    for(i=0;i<n;i++){

      cin>>m;
      while(m--)
	{
	  cin>>a;
	  adj[a].push_back(i);
	  adj[i].push_back(a);
	}
    }
    for(i=0;i<n;i++)
    {
      vertex[i].parent=0;
      vertex[i].visited=-1;
      vertex[i].color=-1;
      vertex[i].index=i;
    }
    long long int flag =0;
    long long int count =0;
    for(i=0;i<n;i++){
      if(vertex[i].visited == -1){
	check = dfs(vertex[i]);
	if(check){
	  count ++;
	}
	else{
	  cout<<"0"<<endl;
	  flag =1;
	  break;
	}
      }
    }

    if(flag ==0){
      long long int res = 1;
    
      for(i=0;i<count;i++){
	res = (res*2)%SIZE;
      }
      cout<<res<<endl;
    }
    for(i=0;i<n;i++)
      adj[i].clear();
  }
}


int dfs(node &s)
{
  node temp;
  s.parent=0;
  s.visited=1;
  s.color=0;
  stack <node> Q;
  Q.push(s);
  while(!Q.empty())
    {
      list <int >::const_iterator it;
      temp=Q.top();
      Q.pop();
      for(it=adj[temp.index].begin();it!=adj[temp.index].end();it++)
	{
	  if(vertex[*it].color==temp.color)
	    return 0;
	  if(vertex[*it].visited!=1)
	    {
	      vertex[*it].parent=temp.index;
	      vertex[*it].visited=1;
	      vertex[*it].color=temp.color ^ 1;
	      Q.push(vertex[*it]);
	    }
	}
    }
  return 1;
}





bool bfs(node &s)
{
  node temp;
  s.parent=0;
  s.visited=1;
  s.color=0;
  queue <node> Q;
  Q.push(s);
  while(!Q.empty())
    {
      list <int >::const_iterator it;
      temp=Q.front();
      Q.pop();
      for(it=adj[temp.index].begin();it!=adj[temp.index].end();it++)
	{
	  if(vertex[*it].color==temp.color)
	    return 0;
	  if(vertex[*it].visited!=1)
	    {
	      vertex[*it].parent=temp.index;
	      vertex[*it].visited=1;
	      vertex[*it].color=temp.color ^ 1;
	      Q.push(vertex[*it]);
	    }
	}
    }
  return 1;
}

