#include<iostream>
using namespace std;
void print_arr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout <<arr[i] << "  " ;
    }
    cout <<endl;
}
void util(int arr[], int size){
    arr[0] = 23;
    cout << "Printing in Util Fun " <<endl;
    print_arr(arr, 3);
}

int main(){
    int arr[3] = {3, 6 ,9};
    util(arr, 3);
    cout << "Printing in main " <<endl;
    print_arr(arr, 3);
}