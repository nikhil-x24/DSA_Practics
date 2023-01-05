#include<iostream>
#include<string.h>
using namespace std;

bool checkAnagram(string a, string b){
    int freq[26] = {0};

    //inc count for string a
    for(int i = 0; i< a.length(); i++){
        char ch = a[i];
        int index = ch - 'a';
        freq[index++];
    }

    //dec count for string b
    for(int i = 0; i< b.length(); i++){
        char ch = b[i];
        int index = ch - 'a';            //mapping char
        freq[index--];
    }

    //checking
    bool flag = true;
    for(char i = 'a'; i <= 'z'; i++){
        if(freq[i] != 0){
            flag = false;
            return false;
        }
    }
    return true;
}

int main(){
    string a = "erman";
    string b = "likhiN";
    cout << checkAnagram(a, b) << endl;
}