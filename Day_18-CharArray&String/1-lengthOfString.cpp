#include<iostream>
using namespace std;
#include<string.h>

int length(char arr[]){       //no need to pass size
    int count = 0;
    
    for(int i = 0; arr[i] != '\0'; i++){
        count++;
    }
    return count;
}

int  main(){
    char name[50] = "network billa";
    cout << length(name) <<endl;
    cout <<"Predefine Function : "<< strlen(name);
}