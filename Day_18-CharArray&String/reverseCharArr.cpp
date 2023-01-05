#include<iostream>
#include<string.h>
using namespace std;

void rev(char arr[]){
    int l = strlen(arr);
    int s = 0;
    int e = l - 1;
    while(s <= e){
        swap(arr[s++], arr[e--]);
    }
}

int main(){
    char name[7] = "nikhil";
    rev(name);
    cout << name;
}