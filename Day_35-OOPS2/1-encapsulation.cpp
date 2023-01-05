#include<iostream>
using namespace std;

class human{

    //propeties
    private:
    int age;
    int weight;
    string name;

    public:
    int getAge(){
        return this-> age;
    }

};

int main(){
    human obj;

    //DM private hai to, use class ke bahar use nhi kr skte to yhi 
    //encapsulation hai.......

    // obj.age;
    // obj.weight;
    // obj.name;
    return 0;
}