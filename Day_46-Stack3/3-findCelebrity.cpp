#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(int a, int b, int arr[4] [4]){
    return arr[a][b];
}

int findCelebrity(int arr[4][4], int n) {

    stack<int> s;
    //step1: push all elements in the stack
    for(int i=0; i<n; i++) {
        s.push(i);
    }

    //find candidate for celebrity
    while(s.size() > 1) {
        int first = s.top();
        s.pop();

        int second = s.top();
        s.pop();

        if(knows(first,second, arr)) {
            s.push(second);
        }
        else{
            s.push(first);
        }
    }

    ///store candidate
    int candidate = s.top();

    //verification of candidate

    //check row for all 0's
    bool checkRow = true;

    for(int i=0; i<n; i++) {
        if(arr[candidate][i] == 1) {
            checkRow = false;
            break;
        }
    }

    //check COlumn for all 1's except row==col wala case
    bool checkCol = true;

    for(int i=0; i<n; i++) {
        if(i!=candidate && arr[i][candidate] == 0) {
            checkCol = false;
            break;
        }
    }

    //if verification succeeds, candidate is a celbrity 
    if(checkRow && checkCol)
        return candidate;
    else
        return -1;

}

int main(){
    int arr[4] [4] = { {0,0,1,0},
                       {0,0,1,0},
                       {0,0,0,0},
                       {0,0,0,0} };
    
    cout<<"Celebrity is: " << findCelebrity(arr, 4);
                    
}