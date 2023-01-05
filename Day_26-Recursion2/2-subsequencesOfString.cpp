#include<iostream>
using namespace std;

void printPowerSet(string input, int index, string output){
    
    //base case
    if(index == input.length()){
        cout << output <<endl;
        return;
    }

    //RR
    //exclusive
    char ch = input[index];
    printPowerSet(input, index+1, output);

    //inclusive
    output.push_back(ch);
    printPowerSet(input, index+1, output);
}

int main(){
    string str = "ass";
    string ouptut = "";
    printPowerSet(str, 0, ouptut);
}