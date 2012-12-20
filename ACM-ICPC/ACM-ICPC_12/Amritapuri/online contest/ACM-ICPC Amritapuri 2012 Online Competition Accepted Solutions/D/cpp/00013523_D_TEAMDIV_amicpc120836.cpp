#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

class Vertex
{
	public:
	vector<int> neighbours;
};

class Graph
{
	public:
	int nVertices;
	Vertex *vertices;
	int **adjMat;
	
	void displayGraph();
};

class BFT
{
	public:
	Graph G;
	queue<int> bftQueue;
	
	// returns each SCC as a set of vertices //
	int scc();
	
	BFT(Graph graph): G(graph){}
};

int main(){
	
	int nTestCases;
	cin >> nTestCases;
	
	for (int testCaseNo = 0; testCaseNo < nTestCases; testCaseNo++){
	
		// read and prepare the graph //
		Graph G;
		cin >> G.nVertices;
		
		G.adjMat = new int*[G.nVertices];
		for (int i = 0; i < G.nVertices; i++){
			G.adjMat[i] = (int*)(calloc(G.nVertices, sizeof(int)));
		}
		for (int i = 0; i < G.nVertices; i++){		
			int nNeighbours, rivalId;
			cin >> nNeighbours;
			for (int j = 0; j < nNeighbours; j++){
				cin >> rivalId;
				G.adjMat[i][rivalId] = 1;
				G.adjMat[rivalId][i] = 1;
			}
		}
		
		// prepare adjacency list //
		G.vertices = new Vertex[G.nVertices];
		for (int i = 0; i < G.nVertices; i++){
			for (int j = i + 1; j < G.nVertices; j++){
				if (G.adjMat[i][j]){
					G.vertices[i].neighbours.push_back(j);
					G.vertices[j].neighbours.push_back(i);
				}
			}
		}		
	
		// display graph //
		//G.displayGraph();
	
		BFT bftObj(G);
		int nBipartiteSCCs = bftObj.scc();
		if(nBipartiteSCCs){
			int nWays = 1;
			for (int i = 0; i < nBipartiteSCCs; i++){
				nWays = (nWays * 2) % 1000000007;
			}
			cout << nWays << endl;
		}
		else{
			cout << 0 << endl;
		}
		
	}
	
	return 0;
}

int BFT::scc(){
	int nVertices = G.nVertices;

	vector<int> vState;
	vector<int> vPushed;
	for (int i = 0; i < nVertices; i++){
		vState.push_back(0);
		vPushed.push_back(0);
	}
	
	// create vector to store all SCCs //
	int nSCCs = 0;
	
	int nUndiscovered = nVertices;
	while(nUndiscovered){
		// find the first vertex not yet part of an SCC //
		for (int i = 0; i < nVertices; i++){
			if(!vState.at(i)){
				bftQueue.push(i);
				vPushed.at(i) = 1;
				break;
			}
		}
		// start a new SCC //
		int sizeOfSCC = 0;
		while(!bftQueue.empty()){
			// dequeue and read the vertex at the front of the queue //
			int vIndex = bftQueue.front();
			bftQueue.pop();
			
			if(vState.at(vIndex)){
				continue;
			}
			// mark the vertex as visited //
			vState.at(vIndex) = 1;
			
			// decrement number of undiscovered vertices //
			nUndiscovered--;

			// increment size of SCC //
			sizeOfSCC++;
			
			// debug //
			//cout << vIndex << "\n";
			
			vector<int> neighbours = G.vertices[vIndex].neighbours;
			vector<int> unpoppedNeighbours;
			for (int i = 0; i < neighbours.size(); i++){
				int nbIndex = neighbours.at(i);
				if(!vState.at(nbIndex)){
					unpoppedNeighbours.push_back(nbIndex);
				}
			}
			for (int i = 0; i < unpoppedNeighbours.size(); i++){
				for (int j = 0; j < unpoppedNeighbours.size(); j++){
					// if the two nodes are at the same level and have an edge between them, then this component can't be bipartite //
					if (!vPushed.at(i) && !vPushed.at(j) && G.adjMat[unpoppedNeighbours.at(i)][unpoppedNeighbours.at(j)]){
						return 0;
					}
				}
			}
			for (int i = 0; i < unpoppedNeighbours.size(); i++){
				bftQueue.push(unpoppedNeighbours.at(i));
				vPushed.at(i) = 1;
			}
		}
		
		// push the newly discovered (completely) SCC in to the list of SCCs //
		if(sizeOfSCC){
			nSCCs++;
		}
		//cout << "undiscovered : " << nUndiscovered << "\n";
	}
	return nSCCs;
}

void Graph::displayGraph(){
	for (int i = 0; i < nVertices; i++){
		cout << i << " : ";
		
		vector<int> neighbours = vertices[i].neighbours;
		for (int j = 0; j < neighbours.size(); j++){
			cout << neighbours.at(j) << " | ";
		}
		cout << "\n\n";
	}
}
