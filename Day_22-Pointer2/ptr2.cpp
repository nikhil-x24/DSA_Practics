#include<iostream>
using namespace std;

void fun1(int **q){
    *q = *q+1;
}

int main(){
    int a = 5;
    int *p = &a;
    int **q = &p;

    cout <<"Befor " << q <<endl;
    cout <<"Befor " << *q <<endl;
    cout <<"Befor " << **q <<endl <<endl;
    
    fun1(q);
    cout <<"after " << q <<endl;
    cout <<"after " << *q <<endl;
    cout <<"after " << **q <<endl;
}