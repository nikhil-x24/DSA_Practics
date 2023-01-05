//combination in string of digit
#include<iostream>
using namespace std;

void findCombo(string input, int i, string output){
    //base case
    if(i == input.length()){
        cout << output <<endl;
        return;
    }
    char ch = input[i];

    //no space_put char withoutSpace
    output.push_back(ch);
    findCombo(input, i + 1, output);

    //withSpace put char 
    output.push_back(' ');
    if(input[i+1] != '\0'){
        findCombo(input, i+1, output);
    }

}

int main(){
    string str = "123";
    string output = "";
    int index = 0;
    findCombo(str, index, output);
}