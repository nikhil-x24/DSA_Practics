#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<vector>
#include<limits.h>
#include<set>
using namespace std;

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

    //Dijkstra Algorithm   -> TC = 0(E log V)
    vector<int> dijkstra(int src, int n ) {

        //distance wala dS -> n size ka banao aur usse INT_MAX se initi kro
        vector<int> dist(n, INT_MAX);

        //<distance, nodeName>
        set<pair<int, int> > st;

        //initial step:
        dist[src] = 0;
        st.insert(make_pair(0,src));

        while(!st.empty()) {
            //step1: get the top element
            //address se value accses krni hai to defrence ka use kre ge like *
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
                    //if me aana ka matlb nai recored bane gi to -> remove old record
                    auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                    //if record is found, then erase it
                    if(record != st.end()) {
                        st.erase(record);
                    }

                    //dist update
                    dist[neighbour.first] = nodeDistance + neighbour.second;

                    //push new record
                    st.insert(make_pair(dist[neighbour.first], neighbour.first));
                }
            }
        }
        return dist;
    } 

};

int main(){

    Graph <int> g;
    g.addEdge(0,1, 5,0);
    g.addEdge(0,2, 8,0);
    g.addEdge(1,2, 9,0);
    g.addEdge(1,3, 2,0);
    g.addEdge(2,3, 6,0);

    cout << "Print Adjancency List : " <<endl;
    g.printAdj();
    
    vector<int> ans = g.dijkstra(0, 4);

    cout << "Print Shortest Path using Dijkstra ALgorithm : " << endl;
    for(auto i:  ans){
        cout << i << " ";
    }cout << endl;
}