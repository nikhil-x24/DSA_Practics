#include<iostream>
using namespace std;

// class creation
class Human {

    //properties -> Data Members
    public:
    char gender;
    int age;

    //behaviour

    // //constructor
    // Human() {
    //     cout << "I m in constructor " << endl;
    //     age = 1;
    //     gender = 'M';
    // }

    // ~Human(){
    //     cout << "Destructor called" << endl;
    // }

};

int main() {

    // Human obj1;
    // cout << obj1.age = 10;

    //object creation
    Human *obj = new Human();
    //cout << sizeof(obj) << endl ; //agar char->1, int ->4 byte leta hai to 
                                 //ans 8 kyu aa rha hai ? EXPLORE..........
    //Intilazied
    (*obj).age = 23;

    //access
    //cout << obj1.age << endl;
    cout << (*obj).age << endl;
    
    return 0;
};