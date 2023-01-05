#include<iostream>
using namespace std;

bool check(string str, int i, int j){
    
    //base case
    if(i > j)
        return true;
    
    if(str[i] != str[j]){
        return false;
    }
    else{
        //RR
        return check(str, i+1, j-1);
    }
}

int main(){
    string name = "ana";
    bool isPalin = check(name, 0, name.length() - 1);

    if(isPalin){
        cout << "It's a Palindrome " <<endl;
    }
    else{
        cout << "It's not a palindrome " <<endl;
    }
}