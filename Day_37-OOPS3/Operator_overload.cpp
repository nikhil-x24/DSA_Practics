#include<iostream>
using namespace std;


class Demo {

    public:
    int first;
    int second;
    static int total;

    //binary op overloading
    Demo operator+ (Demo& temp) {
        Demo result;
        result.first = this->first + temp.first;
        result.second = this->second + temp.second;
        return result;
    }

    //unary op overloading
    void operator++ () {
        cout << "Unary operator overloaded" << endl;
    }
};

class Human {
    public:
    int hands;
    int legs;
};
 
// << op overloading ->>>>> but this op overloading outside of class....
void operator<< (ostream& os, Demo& obj) {
    cout << obj.first << " ";
    cout << obj.second << " " << endl;
}

void operator<< (ostream& os, Human& obj) {
    cout << obj.hands << " ";
    cout << obj.legs << " " << endl;
}

//definition of static variable-> w/o create object
int Demo::total = 0;

class Base {
    public:     //virtual krne ke bad derived class access
    virtual void speak() {
        cout << "I m in Base class" << endl;
    }
};

class Derived: public Base {
    public:
    void speak() {
        cout << "I m in derived class" << endl;
    }
};

int main() {

    Base* bptr;
    Derived dobj;
    bptr = &dobj;
    bptr->speak();

    // Demo a;
    // Demo b;

    // Demo c = a+b;

    // ++a;
    // a++;

    // Demo obj;
    // cout << obj ;
    // cout << obj.total << endl;
    // cout << Demo::total << endl;


    // Human h;
    // cout << h ;
    return 0;
}