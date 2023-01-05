#include<iostream>
#include<string.h>
using namespace std;

// int getLength(char arr[]){
//     int count = 0;
//     for(int i = 0; arr[i] != '\0'; i++){
//         count++;
//     }
//     return count;
// }

bool checkPalindrome(char a[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(a[s] != a[e])
            return 0;
        else{
            s++;
            e--;
        }
    }
    return 1;
}

int main(){
    char name[20];
    cout <<"Enter your name -> ";
    cin >> name;

    cout <<"Your name is ";
    cout << name <<endl;
    //int len = getLength(name);
    int l = strlen(name);

    cout << "Check palindrome or not " <<checkPalindrome(name, l); 
}