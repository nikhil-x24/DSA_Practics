#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<string> q;
    q.push("Nikhil");
    q.push("Kumar");
    q.push("Verma");

    cout << "First -> " <<q.front() <<endl;
    cout << "Size Befor pop -> " <<q.size() <<endl;
    q.pop();

    cout << "After POP First -> " <<q.front() <<endl;
    cout << "Size After pop -> " <<q.size() <<endl;


}