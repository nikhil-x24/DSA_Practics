//i/p -> 41
//o/p -> four one

#include<iostream>
using namespace std;

void sayDigit(int n, string arr[]){

    //base case
    if(n == 0)
        return;
    
    //proccessing
    int digit = n % 10;
    n = n / 10;
    
    //RR
    sayDigit(n, arr);

    cout << arr[digit] <<" ";

}

int main(){
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", 
                      "Seven", "Eight", "Nine"};
    int n;
    cout << "Enter a no. ";
    cin >> n;

    cout <<endl;
    sayDigit(n, arr);
    cout <<endl;

    return 0;
}