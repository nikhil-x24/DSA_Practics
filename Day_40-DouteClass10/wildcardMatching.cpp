#include<iostream>
using namespace std;

bool solve(int i, int j, string pattern, string& str) {
    //dono me se koi nhi bacha, sare match ho gye
    if(i< 0 && j< 0)
        return true;
    //pattern me kuch nhi bacha pr string me bachha hua hai -> matlb glti hai
    if(i< 0 && j>= 0)
        return false;
    //patter me bacha hua hai, pr string me kuch bachha hai
    if(i>=0 && j<0){
        for(int k=0; k<=i; k++){
                
            if(pattern[k] != '*')
                return false;
        }
        return true;
    }
    
    if(pattern[i] == str[j] || pattern[i] == '?')
        return solve(i-1, j-1, pattern, str);

    else if(pattern[i] == '*')
        return ( (solve(i,j-1, pattern, str)) || (solve(i-1, j, pattern, str)) );

    else
        return false;
}
    
bool isMatch(string s, string p) {
                
    return solve(p.length()-1, s.length()-1, p, s);
}

int main(){
    string s = "jiffvnij";
    string p = "j?";
    cout << isMatch(s, p);
}