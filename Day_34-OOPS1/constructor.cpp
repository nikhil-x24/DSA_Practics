#include<iostream>
using namespace std;

// class creation
class Human {
    //properties -> Data Members
    public:
    char gender;
    int age;

    //behaviour

    //constructor
    Human() {
        cout << " I m in constructor " << endl;
        age = 1;
        gender = 'f';
    }

    //parameterised constructor
    Human(int age, char gender) {
        cout << "I m in P Constructor" << endl;
        this -> age = age;
        this -> gender = gender;
    }

    //copy constructor
    Human(Human& temp) {
        cout << "I m in COPY Constructor" << endl;
        this->age = temp.age;
        this->gender = temp.gender;
    }
};

int main() {

    //static
    Human ramesh;
    ramesh.age = 123;
    cout << ramesh.age << endl;

    //dynamic 
    Human *suresh = new Human();
    cout << suresh->age << endl;

    //parameterised constructor
    Human *paraObj = new Human(20, 'M');
    cout << paraObj -> gender << endl;

    //copy constructorr
    Human copyCon(ramesh);
    cout << copyCon.age << endl;

    delete suresh;
    delete paraObj;

    return 0;
}