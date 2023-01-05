//Print fibancci number
#include<iostream>
using namespace std;
void print_fib(int n){
    int first = -1;
    //f=0
    int second = 1;
    //cout << first <<" " <<second <<" ";
    for(int i = 0; i < n; i++) /*(n-2) -> iss liye kyu ki 0, 1 
                                print ho chuka hai, to loop n-2 tak hi chle ga */
    {
        int sum = first + second;
        cout << sum <<" ";
        first = second;
        second = sum;
    }
}
int main(){
    int n;
    cout <<"Enter term. ";
    cin>>n;
    print_fib(n);
    return 0;
}