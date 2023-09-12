import java.util.*;
import java.math.*;
import java.io.*;

public class Team {
	public static void main(String args[]) throws IOException {
		BufferedReader c=new BufferedReader(new InputStreamReader(System.in));
		//Scanner c = new Scanner(System.in);
		int T=Integer.parseInt(c.readLine());
		//int T = c.nextInt();
		for (int t = 0; t < T; t++) {
			int N=Integer.parseInt(c.readLine());
			uGraph U = new uGraph(N);
			for (int i = 0; i < N; i++) {
				String s = c.readLine();
				StringTokenizer st = new StringTokenizer(s);
				st.nextToken();
				while(st.hasMoreTokens()){
					int index = Integer.parseInt(st.nextToken());
					U.add_edge(i, index);
				}
			}
				List<LinkedList<Integer>> l = U.getConnectedComponents();
				if(l==null){
					System.out.println(0);
				}
				else {
					int res=1;
					int mod = 1000000007;
					for (int j = 0; j < l.size(); j++) {
						res=(res*2)%mod;
					}
					System.out.println(res);
				}
			
			c.readLine();
			
		}
		
	}
}

/*Undirected graph class. Vertices are indexed 0-->N-1*/
class uGraph {
	int N; //number of nodes
	List<Integer> edge_list[];

	@SuppressWarnings("unchecked")
	public uGraph(int N) {
		this.N = N;
		edge_list = new LinkedList[N];
		for (int i = 0; i < N; i++)
			//create N Linked Lists
			edge_list[i] = new LinkedList<Integer>();
	}

	/*
	 * Adds a new undirected edge u-v to the graph
	 */
	public void add_edge(int u, int v) {
		edge_list[u].add(v);
		edge_list[v].add(u);
	}

	/*
	 * Returns a List containing >=1 linked lists. Each linked list 
	 * is a separate connected component of the undirected graph.
	 */
	public List<LinkedList<Integer>> getConnectedComponents() {
		List<LinkedList<Integer>> scc = new LinkedList<LinkedList<Integer>>(); //a list of linked lists	
		boolean visited[] = new boolean[N];
		int level[] = new int[N];
		for (int i = 0; i < N; i++) {
			if (!visited[i]) //choose an unvisited node
			{
				visited[i] = true;
				level[i]=0;
				LinkedList<Integer> newComponent = new LinkedList<Integer>(); //a Linked List for the new component
				Queue<Integer> Q = new LinkedList<Integer>(); //a queue for BFS
				Q.add(i);
				newComponent.add(i);
				int l=0;
				while (!Q.isEmpty()) {
					l++;
					int node = Q.poll();
					Iterator<Integer> it = edge_list[node].iterator();
					while (it.hasNext()) {
						int neighbour = it.next();
						if (!visited[neighbour]) {
							visited[neighbour] = true;
							level[neighbour]=l;
							Q.add(neighbour);
							newComponent.add(neighbour);
						}
						else {
							if(level[node]==level[neighbour]) {
								return null;
							}
						}
					}
				}
				scc.add(newComponent); //add a new strongly connected component
			}
		}
		return scc;

	}
}