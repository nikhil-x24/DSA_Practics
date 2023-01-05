#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;

    s.insert(4);
    s.insert(1);
    s.insert(5);
    s.insert(0);
    s.insert(5);
    s.insert(0);
    s.insert(4);
    s.insert(1);
    s.insert(9);

    cout <<"Print all element ->  " ;
    for(auto i : s){     //log(n)
        cout << i << " ";
    }
    cout <<endl;

    cout << "Erase First element ->  ";
    s.erase(s.begin());
    for(auto i : s){     
        cout << i << " ";
    }
    cout <<endl;

    cout << "Erase 2nd element ->  ";
    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);
    for(auto i : s){     
        cout << i << " ";
    }
    cout <<endl;


    cout <<"5 is present -> "<< s.count(5) <<endl;
}