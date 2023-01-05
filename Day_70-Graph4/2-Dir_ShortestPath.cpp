#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;

template <typename T>
class Graph {
    public:
        map<T, list<pair<T, T> > > adjList;
        //map<T, list<T> > adjList;

    void addEdge(T u, T v, T weight) {
        //for u->v
        pair<int, int> p = make_pair(v,weight);
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
    void topoSortDFS(int node, map<int, bool>& visited, stack <int>& topo) {
        
        visited[node] = true;

        for(auto neighbour : adjList[node]) {
            if (!visited[neighbour.first]) {
                topoSortDFS(neighbour.first, visited, topo);
            }
        }
        //catch
        topo.push(node);
    }

    //find shortest path
    void getShortestPath(int src, vector<int>& dist, stack<int>& s){
        dist[src] = 0;
        while(!s.empty()){
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX){
                for(auto i : adjList[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
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

    //Topological Sort
	int n = 6;
    map<int, bool> visited;
    stack<int> st;

    for(int i= 0; i <n; i++){
        if(!visited[i]){
            g2.topoSortDFS(i, visited, st);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for(int i = 0; i<n; i++){
        dist[i] = INT_MAX;
    }

    g2.getShortestPath(src, dist, st);

    cout << "Ans is: " <<endl;
    for(int i = 0; i < dist.size(); i++){
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;

}