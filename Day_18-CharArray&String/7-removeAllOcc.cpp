/* i/p -> da'abc'baabcbc
       -> daba'abc'bc
       -> dab'abc'
   o/p -> dab             */

#include<iostream>
#include<string.h>   //find -> first occ nikalta hai
using namespace std;

string removeAll(string s, string part){
    while(s.length() != 0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << removeAll(s, part);
}