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

    //topological sort ->BFS

    void topoSort() {
        //step1: find out all Indegrees
        map<int, int> indegree;

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
        queue<int> q;
        
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
};

int main() {

	Graph<int> g2;
	g2.addEdge(1,2, 1);
	g2.addEdge(1,3, 1);
	g2.addEdge(2,5, 1);
	g2.addEdge(3,5, 1);
	g2.addEdge(5,4, 1);

    cout << "Printing the Adjacency List " << endl;
    g2.printAdj();

	cout << endl << "Print Topological Sort : " << endl;
    g2.topoSort();

    return 0;
}