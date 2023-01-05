#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<vector>
#include<limits.h>
#include<set>
using namespace std;      ///////////////error

template <typename T>
class Graph {
    public:
        map<T, list<pair<T, T> > > adjList;
        //map<T, list<T> > adjList;
/*
    void addEdge(T u, T v, T weight) {
        //for u->v
        pair<int, int> p = (make_pair(v,weight));
        adjList[u].push_back(p);  
    }
*/

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

    void printAdj() {
        
        for(auto i: adjList) {
            cout << i.first << " -> " ;
            
            for(auto j: i.second) {
                cout << "[" << j.first << ", " << j.second << "], ";
                //cout << j << ', ' ;
            }    
            cout << endl;
        }
    }

    //Bellman Ford Algorithm   -> TC = 0(E.V) ; SC = 0(V)
    vector<int> bellmanFord(int node, int m, int src, 
                            vector<vector<int>>edges) {

        //distance wala dS -> n+1 size ka banao aur usse INT_MAX se initi kro
        vector<int> dist(node+1, INT_MAX);

        //initial step:
        dist[src] = 0;
      
        //(n-1) time
        for(int i = 1; i <= node; i++){
            //traverse on add list
            for(auto j : edges){
                int u = j.first;
                int v = j.second;
                int wt = j.third;

                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }

        //check for neg cycle
        bool flag = 0;
        for(auto j : adjList){
            int u = j.first;
            int v = j.second;
            int wt = j.third;

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                cout << -1; 
                flag = 1; 
                break;    
            }
        }

        if(!flag) {
            for(int i = 0; i<node; i++) {
                cout << dist[i] << " ";
            }
        }
    } 

};

int main(){

    Graph <int> g;
    g.addEdge(1,2, 2,1);
    g.addEdge(2,3, -1,1);
    g.addEdge(1,3, 2,1);

    cout << "Print Adjancency List : " <<endl;
    g.printAdj();
    
    vector<int> ans = g.bellmanFord(3, 3, 1);

    cout << "Print Shortest Path -> Bellman Ford Algorithm : " << endl;
    for(auto i:  ans){
        cout << i << " ";
    }cout << endl;
}