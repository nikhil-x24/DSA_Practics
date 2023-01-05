#include<iostream>
using namespace std;

void print(int n){
    //base case
    if(n < 1)
        return;
    
    //cout<< n << " " ;

    //RR
    print(n-1);

    //Processing
    cout << n << " ";

}

int main(){
    int n;
    cout << "Enter No. : ";
    cin >> n;
    print(n);
}