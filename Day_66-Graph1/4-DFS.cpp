#include<iostream>
#include<map>
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

    //DFS
    void dfs(int src, map<int, bool>& visited ) {
        visited[src] = true;
        cout << src << ", ";

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour]) {
                //RR
                dfs(neighbour, visited);
            }
        }
    }

};

int main() {

    Graph<int> g;
    g.addEdge(0, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(1, 3, 0);
    
    cout << "Printing DFS Traversal " << endl;
    
    map<int, bool> visited;
    //to handle graph with disconnected components
    for(int i=0; i<5; i++) {
        if(!visited[i]) {
            g2.dfs(i, visited);
        }
    }

    //Connected Componets
    //g2.dfs(0, visited);
}