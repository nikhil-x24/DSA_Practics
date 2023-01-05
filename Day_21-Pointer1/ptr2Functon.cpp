#include<iostream>
using namespace std;

void fun(int *p){
    p =p +1; 
}
void fu(int *p){
    *p =*p +1;
}

int main(){

    int  a = 5;
    int *p = &a;

    cout <<"Befor " <<p <<endl;
    cout <<"Befor " <<*p <<endl;

    fun(p);
    fu(p);

    cout <<"after " <<p <<endl;
    cout << "after " <<*p <<endl; 

}