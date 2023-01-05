#include<iostream>
using namespace std;

void solve(string s, string &output, int n, int i){
    if(n<=0){
        output.push_back(s[i]);
        return;
    }

    int k = s[0];
    while(k--){
        if("[" || "]")continue;
        output.push_back(s[i]);
    }
    k+=3;
    solve(s,output,n-1,i+1);
}
string decodeString(string s) {
    string output="";
    int n=s.length();
    solve(s,output,n,0);
    return output;
}

int main(){
    string s = "3[a]2[bc]";
    cout << decodeString(s);
}