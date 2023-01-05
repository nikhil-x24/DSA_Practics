#include<iostream>
using namespace std;

void reverse(string &str, int s, int e){     

    /*
    1-> without & ke yha ek cpy bne gi aur jb hm 'main' me print kre ge to 
        wo wyse hi rhe ga ..., iss liye & ka use kro
    2-> ya fir reverse fun me hi ans ko print kra do.......
    */

    cout << "call recieved for " << str <<endl;
    //base case
    if(s > e)
        return;
    swap(str[s++], str[e--]);

    //RR
    reverse(str, s, e);
}

int main(){
    string name = "Nikhil Verma";
    reverse(name, 0, name.length() - 1);
    cout << name <<endl;

}