import java.util.*;
import java.math.*;
import java.io.*;

public class Main
	{
	public static void main(String args[]) throws IOException
		{
		BufferedReader c=new BufferedReader(new InputStreamReader(System.in));
		//Scanner c=new Scanner(System.in);
		int T=Integer.parseInt(c.readLine());
		for(int t=0;t<T;t++)
			{
			int N=Integer.parseInt(c.readLine());
			//System.out.println("N= "+N);
			uGraph G=new uGraph(N);
			for(int i=0;i<N;i++)
				{
				//System.out.println("for :"+i );
				StringTokenizer st=new StringTokenizer(c.readLine());
				int K=Integer.parseInt(st.nextToken());
				for(int j=0;j<K;j++)
					{
					int v=Integer.parseInt(st.nextToken());
					//System.out.println("\t v= "+v);
					G.add_edge(i,v);
					}
				}
			int color[]=new int[N];
			boolean valid=true;
			for(int i=0;i<N;i++)
				color[i]=-1;
			for(int i=0;i<N;i++)
				{
				if(color[i]==-1)
					{
					//System.out.println("picking "+i);
					color[i]=0;
					Queue<Integer> Q=new LinkedList<Integer>();
					Q.add(i);
					while(!Q.isEmpty())
						{
						int head=Q.poll();
						//System.out.println("\thead = "+head);
						int headColor=color[head];
						for(int v:G.edge_list[head])
							{
							if(color[v]==-1)
								{
								color[v]=(1+headColor)%2;
								//System.out.println("\t\tadding "+v);
								Q.add(v);
								}
							else
								{
								if(color[v]==headColor)
									{
									//System.out.println("color of "+v+" same as color of "+head);
									valid=false;
									}
								}
							}
						}
					}
				}
			if(!valid)
				{
				System.out.println("0");
				c.readLine();
				continue;
				}
			else
				{
				List<LinkedList<Integer>> S=G.getConnectedComponents();
				int n=S.size();
				long ans=1;
				for(int i=0;i<n;i++)
					{
					ans*=2;
					ans%=1000000007;
					}
				System.out.println(ans);
				}
			String s= c.readLine();
			}
		}
	}

/*Undirected graph class. Vertices are indexed 0-->N-1*/
class uGraph
	{
	int N; //number of nodes
	List<Integer> edge_list[];

	@SuppressWarnings("unchecked")
	public uGraph(int N)
		{
		this.N=N;
		edge_list=new LinkedList[N];
		for(int i=0;i<N;i++)
			//create N Linked Lists
			edge_list[i]=new LinkedList<Integer>();
		}

	/*
	 * Adds a new undirected edge u-v to the graph
	 */
	public void add_edge(int u, int v)
		{
		edge_list[u].add(v);
		edge_list[v].add(u);
		}

	/*
	 * Returns a List containing >=1 linked lists. Each linked list 
	 * is a separate connected component of the undirected graph.
	 */
	public List<LinkedList<Integer>> getConnectedComponents()
		{
		List<LinkedList<Integer>> scc=new LinkedList<LinkedList<Integer>>(); //a list of linked lists	
		boolean visited[]=new boolean[N];
		for(int i=0;i<N;i++)
			{
			if (!visited[i]) //choose an unvisited node
				{
				visited[i]=true;
				LinkedList<Integer> newComponent=new LinkedList<Integer>(); //a Linked List for the new component
				Queue<Integer> Q=new LinkedList<Integer>(); //a queue for BFS
				Q.add(i);
				newComponent.add(i);

				while (!Q.isEmpty())
					{
					int node=Q.poll();
					Iterator<Integer> it=edge_list[node].iterator();
					while (it.hasNext())
						{
						int neighbour=it.next();
						if (!visited[neighbour])
							{
							visited[neighbour]=true;
							Q.add(neighbour);
							newComponent.add(neighbour);
							}
						}
					}
				scc.add(newComponent); //add a new strongly connected component
				}
			}
		return scc;
		}
	}

//must declare new classes here