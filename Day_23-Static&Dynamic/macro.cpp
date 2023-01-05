#include<iostream>
using namespace std;

#define AREA(l, b) (l * b)       //macro

int main(){
    int l1 = 10;
    int l2 = 5 , area;
    area = AREA(l1, l2);
    cout <<area;
}
