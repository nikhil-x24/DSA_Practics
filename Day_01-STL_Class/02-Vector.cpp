#include<iostream>
#include<vector>
using namespace std;

int main(){

    //size-> kitne element hai
    //capacity -> ki element ke liye space hai
    
    vector<int> a(5, 1);  //size-> 5; intailiy all no with -> 1
    cout << "Print a  " << endl;
    for(int i: a){
        cout << i <<" ";
    }cout << endl;

    vector<int> v;  //intial iska size hai 0
    cout <<"Capacity -> " <<v.capacity() << endl;

    v.push_back(1);
    cout <<"Capacity -> " <<v.capacity() << endl;

    v.push_back(2);
    cout <<"Capacity -> " <<v.capacity() << endl;

    v.push_back(24);
    cout <<"Capacity -> " <<v.capacity() << endl;

    v.push_back(3);
    cout <<"Capacity -> " <<v.capacity() << endl;
    cout <<"Size -> " <<v.size() << endl;


    cout << "Element at 2nd Index -> " << v.at(2) <<endl;
    cout << "Empty or Not -> " << v. empty() <<endl;

    cout << "First Element -> " << v. front() <<endl;
    cout << "Last Element -> " << v. back() <<endl;


    cout << "Before POP " << endl;
    for(int i: v){
        cout << i <<" ";
    }cout << endl;

    v.pop_back();

    cout << "After POP " << endl;
    for(int i: v){
        cout << i <<" ";
    }cout << endl;

    cout << "Before Clear Size " << v.size() <<endl;
    v.clear();
    cout << "After Clear Size " << v.size() << endl;


}