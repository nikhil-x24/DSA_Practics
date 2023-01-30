#include<iostream>
#include<array>
using namespace std;

int main(){

    //int arr[3] = {1,3,2};
    array<int, 4> arr = {1,2,3,4};
    int size = arr.size();
    cout <<"Size : " << size <<endl;

    for(int i = 0; i< size; i++){
        cout << arr[i] << " " ;
    }
    cout <<endl;

    cout << "Element at 2nd Index -> " << arr.at(2) <<endl;
    cout << "Empty or Not -> " << arr. empty() <<endl;

    cout << "First Element -> " << arr. front() <<endl;
    cout << "Last Element -> " << arr. back() <<endl;
}