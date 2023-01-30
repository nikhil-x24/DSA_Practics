#include<iostream>
using namespace std;

bool search(int arr[],  int size, int trg){
    for(int i = 0; i < size; i++){
        if(arr[i] == trg)
            return true;
    }
    return false;
}

int main(){
    int arr[100], n;
    cout << "Enter no. Element ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int trg;
    cout << "Enter Target ";
    cin >> trg;
    if(search(arr, n, trg))
        cout << "Found";
    else 
        cout << "NotFound ";

}