#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    vector<int> v;

    //insert in sorted order becoz -> BS
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    
    cout<< "Target are present or not -> " 
        <<binary_search (v.begin(), v.end(), 6) <<endl;

    cout<< "Lower Bound -> " 
        <<lower_bound (v.begin(), v.end(), 7) - v.begin() <<endl;

    cout<< "Upper Bound -> " 
        <<upper_bound (v.begin(), v.end(), 5) - v.begin() <<endl;

    //Find MIN & MAX
    int a = 3;
    int b = 5;
    cout << "MAX -> " << max(a, b) <<endl;
    cout << "MIN -> " << min(a, b) <<endl;

    //swap
    swap(a, b);
    cout << "a -> " <<a  <<"\n" <<"b -> " <<b <<endl;

    //Reverse String
    string str = "abc";
    reverse(str.begin(), str.end());
    cout << "String -> " << str << endl;


    //Rotate -> 1 bar
    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "After Rotate : ";
    for(int i: v){
        cout << i << " ";
    }
    cout <<endl;

    //Sort
    //BTS -> Based on IntroSort -> 1> QuickSort, 2> HeapSort, 3> insertionSort
    sort(v.begin(), v.end());
    cout << "After Sorting : " ;
    for(int i: v){
        cout << i << " ";
    }
    cout <<endl;
}