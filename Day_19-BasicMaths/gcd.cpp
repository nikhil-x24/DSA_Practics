#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    
    while(a != b){
        if(a > b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;   //or return b sme hi hoga
        // becoz while tbhi terminate hoga jab a == b ho, to dono sme hi hai..
}

int main(){
    int a, b;
    cout <<"enter the value of a a and b ";
    cin >> a >> b;

    int ans = gcd(a, b);
    cout << "The gcd of " << a << " & " << b << " is " <<ans ;

}