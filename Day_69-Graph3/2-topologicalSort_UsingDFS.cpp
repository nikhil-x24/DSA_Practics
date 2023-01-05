#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
class Graph {
    public:
        map<T, list<pair<T, T> > > adjList;
        //map<T, list<T> > adjList;

    void addEdge(T u, T v, T weight) {
        //for u->v
        pair<int, int> p = (make_pair(v,weight));
        adjList[u].push_back(p);  
    }
/*
    void addEdge(T u, T v, T weight, bool direction) {
        //direction = 0 -> undirected graph
        //direction = 1 -> directed grapp   

        //for u->v
        adjList[u].push_back(make_pair(v,weight));
        //check v->u
        if(direction == 0) {
            adjList[v].push_back(make_pair(u, weight));
        }    
    }
*/
    void printAdj() {
        
        for(auto i: adjList) {
            cout << i.first << " -> " ;
            
            for(auto j: i.second) {
                cout << "(" << j.first << ", " << j.second << "), ";
                //cout << j << ', ' ;
            }    
            cout << endl;
        }
    }

    //topological sort ->DFS    
    vector<int> topoSortDFS(int node, map<int, bool>& visited, stack <int>& st) {
        
        visited[node] = 1;

        for(auto neighbour : adjList[node]) {
            if (!visited[neighbour.first]) {
                topoSortDFS(neighbour.first, visited, st);
            }
        }
        //catch
        st.push(node);

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
		for(int i = 0; i< ans.size(); i++){
			cout << ans[i] << " " ;
		}
    }
};

int main() {

	Graph<int> g2;
	g2.addEdge(0,1, 5);
	g2.addEdge(0,2, 3);
	g2.addEdge(1,2, 2);
	g2.addEdge(1,3, 6);
	g2.addEdge(2,3, 7);
    g2.addEdge(2,4, 4);
	g2.addEdge(2,5, 2);
	g2.addEdge(3,4, -1);
	g2.addEdge(4,5, -2);

    cout << "Printing the Adjacency List " << endl;
    g2.printAdj();

    //topo
    cout << endl << "Print Topological Sort : " << endl;

	int n = 6;
    map<int, bool> visited;
    stack<int> st;

    for(int i = 0; i<n; i++){
        if(!visited[i]){
            g2.topoSortDFS(i, visited, st);
        }
    }
    return 0;    
}



/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
  void findHelper(int node, vector <int>& vis, 
                    stack<int>& st, vector<int> adj[]) {
    vis[node] = 1;

    for (auto neighbour: adj[node]) {
        if (!vis[neighbour]) {
            findHelper(neighbour, vis, st, adj);
        }
    }
    st.push(node);
  }

  public:
    vector<int> topoSort(int N, vector<int> adj[]) {
        stack<int> st;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++) {
            if (vis[i] == 0) {
                findHelper(i, vis, st, adj);
            }
        }

        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }

};

int main() {

  int N = 6;
  vector<int> adj[5 + 1];

  adj[5].push_back(2);
  adj[5].push_back(0);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

  Solution obj;
  vector<int> res = obj.topoSort(6, adj);

  cout << "Toposort of the given graph is:" << endl;
  for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
  }

  return 0;
} 
*/