//check string are rotations same or not

#include<iostream>
using namespace std;

int rot(string a, string b){
    if(a.length() != b.length()){
        return false;
    }
    string temp = a + a;
    if(temp.find(b) == string::npos)
        return false;
    else    
        return true;
}

int main(){
    string a = "bbarba";
    string b = "baabar";
    cout << rot(a, b);
    
}