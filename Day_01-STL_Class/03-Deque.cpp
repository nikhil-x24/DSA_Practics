#include<iostream>
#include<queue>
using namespace std;

int main(){

    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_front(22);

    for(int i : d){
        cout << i <<" ";
    }
    cout << endl;

    // d.pop_back();
    // d.pop_front();

    // cout<< "After pop : ";
    // for(int i : d){
    //         cout << i <<" ";
    // }
    cout << endl;

    cout << "Print first index element : " << d.at(1) <<endl;
    cout << "Front : " << d.front() <<endl;
    cout << "Last : " << d.back() <<endl;
    cout << "Empty or Not : " << d.empty() <<endl;

    cout << "Before Erase : " << d.size() <<endl;
    d.erase(d.begin(), d.begin()+1);     //erase 1 index
    cout << "After Erase : " << d.size() <<endl;

    //print
    for(int i : d){
        cout << i <<" ";
    }
    cout << endl;
}
