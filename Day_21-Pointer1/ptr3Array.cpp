#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};

    cout <<arr <<endl;         //address
    cout <<&arr <<endl;        //point base addess (self refrencing Pointing)
    cout <<&arr[0] <<endl <<endl;

    cout <<arr[0] <<endl;
    cout <<*arr <<endl;        //bcoz  *(arr+0)
    cout <<*(arr+1) <<endl;
    cout <<*(arr+2) <<endl;
    cout <<*(arr+3) <<endl;
    cout <<*(arr+4) <<endl;
    cout <<*(arr+5) <<endl;           //garbege
    cout <<*(arr+6) <<endl <<endl;    //garbege
    //cout <<arr[0] <<endl ;
    
    int i = 0;
    cout <<arr[i] <<endl;       //*(arr + i)
    cout << *(arr+3) <<endl;
    cout <<i[arr] <<endl;       //*(i + arr)
    
}