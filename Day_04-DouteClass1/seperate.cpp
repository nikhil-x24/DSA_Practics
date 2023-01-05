#include <iostream>
using namespace std;
int main(){
    
    int n = 137;
    while(n!=0){
        int digit = n%10;
        cout << "Digit " <<digit <<endl;
        n = n/10;
    }
    cout <<endl;

    //same but using for loop
    for(int a = 892; a!=0; a = a/10){
        int digit = a % 10;
        cout << "Digit " <<digit <<endl;
    }
}