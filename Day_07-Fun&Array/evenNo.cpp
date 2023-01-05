//print even no. till to n
#include<iostream>
using namespace std;

void print_even(int n){
    for(int i = 2; i <= n; i+=2){
        cout << i <<" ";
    }
}
int main(){
    int n = 15;
    print_even(n);
}