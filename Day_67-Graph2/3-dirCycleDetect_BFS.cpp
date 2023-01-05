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

    //Cycle detect using BFS-> Khan's Algo 

    int cycleDectect(int n) {
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
        int cnt = 0;

        while(!q.empty()) {
            int front = q.front();
            cout << front << " ";
            q.pop();

            //inc cnt
            cnt++;

            for(auto neigh: adjList[front]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        if(cnt == n)
            return false;
        else    
            return true;
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

    int n = 5;
    // cout << g2.cycleDectect(n);
    cout << "Path: ";
    int num = g2.cycleDectect(n);
    cout << endl;

    if(num == 1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}