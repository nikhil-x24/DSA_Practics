#include<iostream>
using namespace std;
#include<string.h>

//reverse function
void reverse(char name[], int n){
    int s = 0;
    int e = n-1;
    while (s<e){
        swap(name[s++], name[e--]);
    }
    
}

int getLength(char arr[]){
    int count = 0;
    for(int i = 0; arr[i] != '\0'; i++){
        count++;
    }
    return count;
}

int  main(){
    char name[20] = "network billa";
    int len = getLength(name);
    cout << len << endl;
    cout <<"Predefine Function : "<< strlen(name);
    reverse(name, len);
    cout <<endl;
    cout <<"Reverse Of string is : " <<name;
}