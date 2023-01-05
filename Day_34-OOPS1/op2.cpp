#include <iostream> 
using namespace std; 

//creating class 
class smartphone {
     //class body 
     //Data Members(Properties) 
     string model; 
     int year_of_manufacture;
     bool _5g_supported; 

     //Constructor 
     smartphone (string model_string, int manufacture, bool _5g_) { 
        //initialzing data members 
        model = model_string; 
        year_of_manufacture = manufacture; 
        _5g_supported = _5g_; 
    } 
    //methods 
    void print_details(){ 
        cout<<"Model : "<< model <<endl; 
        cout<<"Year of Manufacture : "<< year_of_manufacture<<endl; 
        cout<<"5g Supported : "<< _5g_supported<<endl; 
    } 
}; 

int main() { 
    //creating objects of smartphoneclass 
    smartphone iphone("iphone 11",2019,false); 
    smartphone redmi("redmi note 11 t",2021,true); 
    smartphone oneplus("oneplus nord",2020,true); 
    
    //accessing class variables 
    int iphone_manufacture_date = iphone.year_of_manufacture; 
    bool redmi_support_5g = redmi._5g_supported; 
    string oneplus_model = oneplus.model;

    //calling methods on objects 
    iphone.print_details(); 
    redmi.print_details(); 
    oneplus.print_details(); 
}