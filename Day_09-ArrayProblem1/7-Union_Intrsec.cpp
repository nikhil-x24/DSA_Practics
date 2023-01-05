//find union and intersection from sorted array
#include<iostream>
using namespace std;
void Union(int arr1[], int arr2[], int m, int n){
    int i = 0, j = 0;
    while(i < m && j < n){
        
        if(arr1[i] < arr2[j])
            cout << arr1[i++]  <<" ";

        else if(arr2[j] < arr1[i])
            cout << arr2[j++] << " ";

        else{   //both are equal
            cout << arr1[i++] <<" ";
            j++;
        }
    }
    //if array empty of arr2 then print all value of arr1
    while(i < m)
        cout << arr1[i++] << " ";

    while(j < n)
        cout << arr2[j++] << " ";
    
    cout << endl;
    cout << endl;
}

void Intersection(int arr1[], int arr2[], int m, int n){
    int i = 0, j = 0;
    
    while(i < m && j < n){

        if(arr1[i] > arr2[j])
            j++;

        else if(arr2[j] > arr1[i])
            i++;

        else{
            //both are equal
            cout << arr1[i] <<" ";
            i++;
            j++;
        }
    }
}

int main(){
    int arr1[] = {1, 2, 5, 8};  //size / m= 4
    int arr2[] = {1, 5, 8, 9};  //size / n= 4
    Union(arr1, arr2, 4, 4 );
    Intersection(arr1, arr2, 4, 4);
}