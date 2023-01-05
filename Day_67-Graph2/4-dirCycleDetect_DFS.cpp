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
    
/*
	void bfs(int src, map<int, bool>& visited) {

		queue<int> q;
		q.push(src);
		
		//map<int, bool> visited;
		visited[src] = true;

		while(!q.empty()) {
			int front = q.front();
			cout << front << ", ";
			q.pop();

			for(auto neighbour: adjList[front]) {
				if(!visited[neighbour] ) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

	void dfs(int src, map<int, bool>& visited ) {
		visited[src] = true;
		cout << src << ", ";

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour]) {
				dfs(neighbour, visited);
			}
		}
	}

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
				if(visited[neighbour] == true &&
					neighbour != parent[front]) {
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
*/

	bool isCyclicDfsDirected(int src, map<int, bool>& visited,
					map<int, bool>& dfsVisited ) {
		visited[src] = true;
		dfsVisited[src] = true;

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour]) {
				bool cycleDetected = isCyclicDfsDirected(neighbour, visited, dfsVisited);
				if(cycleDetected == true)
					return true;
			}
			else if(visited[neighbour] == true && dfsVisited[neighbour] == true) {
				//cycle pressent
				return true;
			}
		}
		//backtrack
		dfsVisited[src] = false;
		return false;
	}
};

int main() {

	Graph<int> g;

	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(2, 4, 1);
	g.addEdge(3, 7, 1);
	g.addEdge(3, 8, 1);
	g.addEdge(4, 5, 1);
	g.addEdge(5, 6, 1);
	//g.addEdge(6, 4, 1);
	g.addEdge(8, 7, 1);

	cout << "Printing the adj list " << endl;
	g.printAdj();

	map<int, bool> visited;
	map<int, bool> dfsVis;
	cout << "Cyclic or not: " << g.isCyclicDfsDirected(1,visited, dfsVis);
	
    return 0;
} 