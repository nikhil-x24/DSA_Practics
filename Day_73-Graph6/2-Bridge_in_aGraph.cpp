#include<iostream>
#include<unordered_map>
#include<list>
#include<map>
#include<list>
#include<queue>
#include<limits.h>
#include<set>
#include<stack>
using namespace std;  /////////////////////////error

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

    void dfs(int node, int parent, unordered_map<int,bool> &vis, vector<int> &disc,
            vector<int> &low, int &timer,unordered_map<int, list<int> > &adj , 
            vector<vector<int>> &result) {
        
        vis[node] = true;
        low[node] = disc[node] = timer++;
        
        for(auto neighbour: adj[node]) {
            if(neighbour == parent)
                continue;
            if(!vis[neighbour]) {
                dfs(neighbour, node, vis,disc,low,timer,adj,result);
                low[node] = min(low[node], low[neighbour]);
                if(low[neighbour] > disc[node])
                {
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(neighbour);
                    result.push_back(ans);
                }
            }
            else {
                //this is the back edge
                low[node] = min(low[node], disc[neighbour]);
            }
        }
    }

    vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
        
        //create adj list
        unordered_map<int, list<int> > adj;
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> parent(v);
        vector<int> disc(v);
        vector<int> low(v);
        unordered_map<int,bool> vis;
        
        for(int i=0; i<v; i++ ) {
            parent[i] = -1;
            disc[i] = -1;
            low[i] = -1;
        }
        
        vector<vector<int> > result;
        int timer = 0;
        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                dfs(i,-1,vis,disc,low,timer,adj, result);
            }
        }
        return result;
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

	
}