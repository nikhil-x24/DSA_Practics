#include<iostream>
using namespace std;
int main(){
    int arr[3] = {1,2,3};
    int *ptr = arr;

     cout << &arr <<endl; //addres
     cout << &ptr <<endl; //pointer -> ka jo address hai
     cout << arr <<endl;  //equalvalt to    &arr
     cout << ptr <<endl;  //adress   same -^  &arr
     cout << *arr <<endl; //equalvalt to *(arr+1) == *arr[i] == i[arr]
     cout << *ptr <<endl;  //1st value in array
}