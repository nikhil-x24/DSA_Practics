#include <iostream>
#include <map>
#include<list>
#include<queue>
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

//Detected Cyclic or not in undirected graph using BFS

	bool isCyclicBfs(int src) {
		map<int, bool> visited;
		map<int, int> parent;
		queue<int> q;

		q.push(src);
		visited[src] = true;
		parent[src] = -1;

		while(!q.empty()) {
			int front = q.front();
			q.pop();

			for(auto neighbour: adjList[front]) {
				if(visited[neighbour] == true && neighbour != parent[front]) {
					return true;
				}
				else if(!visited[neighbour]) {
					q.push(neighbour);
					visited[neighbour] = true;
					parent[neighbour] = front;
				}
			}
		}
		return false;
	}
};

int main() {

	Graph<int> g2;
	g2.addEdge(0,2,0);
	g2.addEdge(2,3,0);
	g2.addEdge(2,4,0);
	g2.addEdge(3,4,0);
	g2.addEdge(1,3,0);

    cout << "Printing the Adjacency List " << endl;
    g2.printAdj();
	cout << "loop present or not: " << g2.isCyclicBfs(0) << endl;
    cout << endl;



    Graph<int> g;
	//Component C1
	g.addEdge(0, 1, 0);
	g.addEdge(1, 2, 0);
	g.addEdge(1, 3, 0);
	g.addEdge(2, 3, 0);
	g.addEdge(3, 4, 0);
	g.addEdge(2, 4, 0);

	//Component - C2
	g.addEdge(5, 6, 0);

	cout << "Printing the Adjacency List " << endl;
	g.printAdj();

	int n = 7;
	map<int, bool> visited;
	//to handle graph with disconnected components
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			bool ans = g.isCyclicBfs(i);
            if(ans == true)
               cout << "Loop Present ";
		}
	}
	cout << endl;
    
    return 0;
} 