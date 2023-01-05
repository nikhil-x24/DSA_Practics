#include<iostream>
using namespace std;

void goHome(int src, int dest){

    cout << "Source " << src << " Destinations " << dest <<endl;

    //base case
    if(src == dest){
        cout << "Aa gya ghar";
        return;
    }

    //RR
    return goHome(src+1, dest);   //src ek step aage badhe ga

}

int main(){
    int dest = 10;
    int src = 1;
    goHome(src, dest);
}