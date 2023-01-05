#include<iostream>
using namespace std;

inline int maxi(int x, int y){
    return (x > y) ? x : y;
}

int main(){
    cout << maxi(20, 10) <<endl;
    cout << maxi(0, 200) <<endl;
    cout << maxi(100, 1010) <<endl;
}