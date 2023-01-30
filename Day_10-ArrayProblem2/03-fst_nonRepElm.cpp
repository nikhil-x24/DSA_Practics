//Find first non repeting element in array

#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int arr[] = {2, 1, 3, 2, 4 ,3};

    //step1
    unordered_map<int, int> freq;
    for(int i = 0; i < 6; i++){
        freq[arr[i]]++;                                            //int currentElement = arr[i];
                                                                   //freq[currentElement]++;
    }

    //step2
    for(int i= 0 ; i < 6; i++){
                                                                   //int currentElement = arr[i];
        if(freq[arr[i]] == 1){                                      //if(freq[currentElement] > 1)
            cout << arr[i] << "  is the ans" <<endl;               //        return currentElement
            break;
        }
    }

}