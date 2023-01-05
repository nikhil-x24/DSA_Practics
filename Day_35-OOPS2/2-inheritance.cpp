#include<iostream>
using namespace std;

class human{
    public:
    int age;
    int weight;
    string name;

    public:
    int getAge(){
        return this-> age;
    }
};

class female: public human{

};

int main(){
    female firstfemale;
    cout << firstfemale.age <<endl;
}