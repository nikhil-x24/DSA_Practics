#include<iostream>
#include<map>
using namespace std;

int main(){
    
    map<int, string> m;

    m[1] = "Nikhil";
    m[2] = "Verma";
    m[13] = "Kumar";

    m.insert({5, "Aman"});

    cout <<"Before Erase " <<endl;
    for(auto i:m){
        cout << i.first << " " <<i.second << endl;
    }

    cout << "Finding 6 -> " << m.count(6) <<endl <<endl <<endl;

    m.erase(13); //only key
    cout <<"After Erase " <<endl;
    for(auto i:m){
        cout << i.first << " " <<i.second << endl;
    }

}