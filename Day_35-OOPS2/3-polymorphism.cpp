#include<iostream>
using namespace std;

//overloading
class math{
    public:
    int add(int a, int b){
        return a+b;
    }

    //method overloading -> no. of parameters
    int add(int a, int b, int c){
        return a+b+c;
    }
    //method overloading -> type of parameters
    int add(int a, float b){
        return a+b;
    }
    /*method overloading -> chg return type ye nhi hoga
    void add(int a, float b){
        return a+b;
    }
    */
};

//overriding
class animal{
    public:
    int age;

    public:
    void speak(){
        cout <<"Animal is speaking" <<endl;
    }
};

class dog : public animal{
    public:
    //method overriding
    void speak(){
        cout <<"Dog is barking" <<endl;
    }
};

int main(){
    math obj;
    obj.add(2,3);
   
    dog obj1;
    obj1.speak();
}