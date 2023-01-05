#include <iostream>
#include <map>
#include<list>
using namespace std;

template <typename T>
class Graph {
	public:
		map<T, list<T> > adjList;

	void addEdge(T u, T v, bool direction) {
		//direction = 0 -> undirected graph
		//direction = 1 -> directed grapp

		//for u->v
		adjList[u].push_back(v);
		//check v->u
		if(direction == 0) {
			adjList[v].push_back(u);
		}	
	}

	void printAdj() {
		for(auto i: adjList) {
			cout << i.first << " -> " ;
			for(auto j: i.second) {
				cout << j << ", "; 
			}	
			cout << endl;
		}
	}

	bool isCyclicDfs(int src, int parent, map<int, bool>& visited) {

		visited[src] = true;

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour]) {
				bool cycleDetected = isCyclicDfs(neighbour, src, visited);
				if(cycleDetected == true)
					return true;
			}
			else if(visited[neighbour] == true && neighbour != parent) {
				//cycle is present
				return true;
			}
		}
		return false;
	}
};

int main() {

	Graph<int> g;

	//Component C1
	g.addEdge(0, 1, 0);
	g.addEdge(1, 2, 0);
	g.addEdge(1, 3, 0);
	g.addEdge(2, 3, 0);
	g.addEdge(3, 4, 0);
	g.addEdge(2, 4, 0);

	//Component - C2
	g.addEdge(5,6,0);

	cout << "Printing the Adjacency List " << endl;
	g.printAdj();

	int n = 7;
	map<int, bool> visited;
	//to handle graph with disconnected components
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			bool ans = g.isCyclicDfs(0, -1, visited);
            if(ans == true)
               cout << "Loop Present ";
		}
	}
	cout << endl;


	Graph<int> g2;
	g2.addEdge(0,2,0);
	g2.addEdge(2,3,0);
	g2.addEdge(2,4,0);
	g2.addEdge(3,4,0);
	g2.addEdge(1,3,0);

    cout << "Printing the Adjacency List " << endl;
    g2.printAdj();

	int parent = -1;
	map<int, bool> visited3;
	cout << "loop present or not " << g2.isCyclicDfs(0, parent, visited3) << endl;
	
    return 0;
} 