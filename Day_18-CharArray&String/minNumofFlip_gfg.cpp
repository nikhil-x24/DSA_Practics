#include<iostream>      //GOLDMAN SACH
#include<string.h>
using namespace std;

//change expected value -> or increment
char flip(char expected){
    if(expected == '0')
        return 1;
    else    
        return 0;
}

int getflips(string str, char expected){
    int cntflips = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != expected){
            cntflips++;
            expected = flip(expected);   //excepeted 0 tha to agla char 1 hoga iss liye update kiya gya hai
        }
    }
    return cntflips;
}

int main(){
    string str = "0110";

    //if ans start with 0
    int ans0 = getflips(str, '0');
    int ans1 = getflips(str, '1');
    int ans = min(ans0, ans1);
    cout <<ans;
}