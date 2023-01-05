#include<iostream>
using namespace std;
#include<string.h>

int getLength(char arr[]){
    int lenght = 0;
    int index  = 0;
    while(arr[index] != '\0'){
        lenght++;
        index++;
    }
    return lenght;      //or index sme hi hoga
}

int  main(){
    char name[10] = "network  ";
    cout << getLength(name) <<endl;
    cout <<"Predefine Function : "<< strlen(name);
}