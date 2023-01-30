//Find common element in 3 sorted array
//HW -> Handle Duplicate element
#include<iostream>
#include<vector>
using namespace std;

vector<int> intersection(vector<int> arr1, vector<int> arr2){
    
    vector<int> ans;
    int i = 0;
    int j = 0;

    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j])
            i++;

        else if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else    
            j++;
    }
    return ans;
}

int main(){
    vector<int> arr1;
    vector<int> arr2;
    vector<int> arr3;
    
    //1st Array
    cout <<"Enter the size of arr1  " <<endl;
    int sizeA;
    cin >> sizeA;
    for(int i = 0; i <sizeA; i++){
        int t;
        cin >> t;
        arr1.push_back(t);
    }

    //2nd Array
    cout <<"Enter the size of arr2  " <<endl;
    int sizeB;
    cin >> sizeB;
    for(int i = 0; i <sizeB; i++){
        int t;
        cin >> t;
        arr2.push_back(t);
    }

    //3rd Array
    cout <<"Enter the size of arr3  " <<endl;
    int sizeC;
    cin >> sizeC;
    for(int i = 0; i <sizeC; i++){
        int t;
        cin >> t;
        arr3.push_back(t);
    }

    vector<int> ans = intersection(arr1, arr2);
    vector<int> output  = intersection(ans, arr3);
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    cout <<endl;
}