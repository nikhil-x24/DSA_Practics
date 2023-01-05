#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<limits.h>
#include<set>
#include<stack>
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
				cout<<j <<", "; 
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

	void topoSort() {
		//step1: find out all indegrees
		map<int, int> indegree;
		queue<int> q;

		//initialse indegree with 0
		for(auto i: adjList) {
			indegree[i.first] = 0;
		}
		
		for(auto i: adjList) {
			for(auto j: i.second) {
				indegree[j]++;
			}
		}

		//step2: push in q, indegree -> 0
		for(auto i: indegree) {
			if(i.second == 0) {
				q.push(i.first);
			}
		}

		//step3: BFS
		while(!q.empty()) {
			int front = q.front();
			cout << front << " ";
			q.pop();

			for(auto neigh: adjList[front]) {
				indegree[neigh]--;
				if(indegree[neigh] == 0) {
					q.push(neigh);
				}
			}
		}
	cout << endl;
		
	}

	/*vector<int> dijkstra(int src, int n ) {
		vector<int> dist(n, INT_MAX);

		//distance, nodeName
		set<pair<int,int> > st;

		//initial step:
		dist[src] = 0;
		st.insert(make_pair(0,src));

		while(!st.empty()) {
			//step1: get the top element
			auto top = *(st.begin());
			//pop
			st.erase(st.begin());

			int nodeDistance = top.first;
			int node = top.second;

			//step2: explore neighbour
			for(auto neighbour: adjList[node]) {
				//neighbour.first -> neighbour node name
				//neighbour.second -> neighbour weight
				
				if(nodeDistance + neighbour.second < dist[neighbour.first]) {
					//remove old record
					auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
					//if record is found, then erase it
					if(record != st.end()) {
						st.erase(record);
					}

					//dist update
					dist[neighbour.first] = nodeDistance + neighbour.second ;

					//push new record
					st.insert(make_pair(dist[neighbour.first], neighbour.first));
				}
			}
		}
		return dist;
	} */

	void dfs(stack<int>& st, map<int,bool>& vis, int node) {
		vis[node] = true;

		for(auto neighbour: adjList[node]) {
			if(!vis[neighbour] ) {
				dfs(st,vis,neighbour);
			}
		}
		st.push(node);
	}

	void transpose(map<int, list<int> >& newAdjList) {
		for(auto i: adjList) {
			int u = i.first;
			for(auto v: i.second) {
				newAdjList[v].push_back(u);
			}
		}
	}

	void revDfs(map<int,bool>& vis, int node, map<int, list<int> >& newAdjList) {
		cout << node << ", ";
		vis[node] = true;

		for(auto neighbour: newAdjList[node]) {
			if(!vis[neighbour]) 
				revDfs(vis, neighbour, newAdjList);
		}
	}
};

int main() {

	Graph<int> g;

	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(2,0,1);
	g.addEdge(2,3,1);
	g.addEdge(3,4,1);

	g.printAdj();

	//Step1: TOPO Orderding
	stack<int> st;
	map<int,bool> vis;
	int n = 5;
	for(int i=0; i<n; i++) {
		if(!vis[i]) {
			g.dfs(st,vis,i);
		}
	}

	//step2: transpose
	map<int,list<int> > newAdjList;
	g.transpose(newAdjList);

	//step3: dfs basis on T.S
	map<int,bool> vis2;
	int count = 0;

	while(!st.empty()) {
		int node = st.top();
		st.pop();
		if(!vis2[node]) {
			count++;
			g.revDfs(vis2, node, newAdjList);
			cout << endl;
		}
	}
	//for(int i = 0; i < ; i++){
	//}
	cout << "Total SCC are: " << count << endl;
	
		
	// Graph<int> g;

	// g.addEdge(0,1,5,0);
	// g.addEdge(0,2,8,0);
	// g.addEdge(1,2,9,0);
	// g.addEdge(1,3,2,0);
	// g.addEdge(2,3,6,0);

	// g.printAdj();
	// vector<int> ans = g.dijkstra(0,4);
	// for(auto i: ans) {
	// 	cout << i << " ";
	// }cout << endl;
	
	// g.addEdge(1,2, 1);
	// g.addEdge(1,3, 1);
	// g.addEdge(2,5, 1);
	// g.addEdge(3,5, 1);
	// g.addEdge(5,4, 1);

	// cout << "Printing adj list " << endl;
	// g.printAdj();

	// cout << endl << " Printing topo sort " << endl;
	// g.topoSort();
	

	
	// Graph<int> g;

	// g.addEdge(1,2, 1);
	// g.addEdge(2,3, 1);
	// g.addEdge(2,4, 1);
	// g.addEdge(3,7, 1);
	// g.addEdge(3,8, 1);
	// g.addEdge(4,5, 1);
	// g.addEdge(5,6, 1);
	// g.addEdge(6,4, 1);
	// g.addEdge(8,7, 1);

	// cout << "Printing the adj list " << endl;

	// g.printAdj();

	// map<int, bool> visited;
	// map<int, bool> dfsVis;
	// cout << "Cyclic or not " << g.isCyclicDfsDirected(1,visited, dfsVis);
	

	// Graph<int> g;

	// //Component C1
	// g.addEdge(0, 1, 0);
	// g.addEdge(1, 2, 0);
	// g.addEdge(1, 3, 0);
	// g.addEdge(2, 3, 0);
	// g.addEdge(3, 4, 0);
	// g.addEdge(2, 4, 0);

	// //Component - C2
	// g.addEdge(5,6,0);

	// cout << "Printing the Adjacency List " << endl;
	// g.printAdj();

	// cout << "printing the bfs traversal  " << endl;
	

	
	// int n = 7;
	// map<int, bool> visited;
	// //to handle graph with disconnected components
	// for(int i=0; i<n; i++) {
	// 	if(!visited[i]) {
	// 		g.bfs(i, visited);
	// 	}
	// }
	// cout << endl;

	// Graph<int> g2;
	// g2.addEdge(0,2,0);
	// g2.addEdge(2,3,0);
	// //g2.addEdge(2,4,0);
	// g2.addEdge(3,4,0);
	// g2.addEdge(1,3,0);
	
	// cout << "Printing DFS Traversal " << endl;
	
	// map<int, bool> visited2;
	// for(int i=0; i<5; i++) {
	// 	if(!visited[i]) {
	// 		g2.dfs(i, visited);
	// 	}
	// }
	// //g2.dfs(0, visited2);

	// cout << "loop present or not " << g.isCyclicBfs(0) << endl;
	// cout << "loop present or not " << g2.isCyclicBfs(0) << endl;

	// int parent = -1;
	// map<int, bool> visited3;
	// //cout << "loop present or not " << g.isCyclicDfs(0, parent, visited3) << endl;
	// cout << "loop present or not " << g2.isCyclicDfs(0, parent, visited3) << endl;
	

  return 0;
} 