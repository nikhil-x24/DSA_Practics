#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
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

//find shortest path in undirected graph -> using BFS

	vector<int> shortestPath(int src, int dest) {
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
				if(!visited[neighbour]) {
					q.push(neighbour);
					visited[neighbour] = true;
					parent[neighbour] = front;
				}
			}
		}
        
        //find shortest path
        vector<int> ans;

        ans.push_back(dest);
        while(parent[dest] != src){
            ans.push_back(parent[dest]);
            dest = parent[dest];
        }
        ans.push_back(src);
        // reverse(ans.begin(), ans.end());
        // return ans;

		cout << "Path: " ;
		for(int i = ans.size() - 1; i>=0; i--){
			cout << ans[i] << "  " ;
		}
		cout << endl;
	}
};

int main() {

	Graph<int> g2;
	g2.addEdge(1,2, 1);
	g2.addEdge(1,3, 1);
	g2.addEdge(1,4, 1);

	g2.addEdge(2,1, 1);
	g2.addEdge(2,5, 1);

    g2.addEdge(3,1, 1);
	g2.addEdge(3,8, 1);

	g2.addEdge(4,1, 1);
	g2.addEdge(4,6, 1);

	g2.addEdge(5,2, 1);
    g2.addEdge(5,8, 1);

	g2.addEdge(6,4, 1);
	g2.addEdge(6,7, 1);

	g2.addEdge(7,6, 1);
	g2.addEdge(7,8, 1);

    cout << "Printing the Adjacency List " << endl;
    g2.printAdj();

    g2.shortestPath(1, 8);
    cout << endl;


/*
    Graph<int> g;
	//Component C1
	g.addEdge(1,2, 1);
	g.addEdge(1,3, 1);
	g.addEdge(1,4, 1);

	g.addEdge(2,1, 1);
	g.addEdge(2,5, 1);

    g.addEdge(3,1, 1);
	g.addEdge(3,8, 1);

	g.addEdge(4,1, 1);
	g.addEdge(4,6, 1);

	g.addEdge(5,2, 1);
    g.addEdge(5,8, 1);

	g.addEdge(6,4, 1);
	g.addEdge(6,7, 1);

	g.addEdge(7,6, 1);
	g.addEdge(7,8, 1);

	//Component - C2
	g.addEdge(9,10, 1);

	cout << "Printing the Adjacency List " << endl;
	g.printAdj();

	int n = 10;
	map<int, bool> visited;

	//to handle graph with disconnected components
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			g.shortestPath(i, 10);
		}
	}
	cout << endl;

*/
    return 0;
} 