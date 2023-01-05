/*
i/p -> test
       t -> 2  ; e -> 1 ; s -> 1
o/p -> t
*/

#include<iostream>
using namespace std;

char maxOccuring(string s){
    int arr[26]={0};

    //create an array of count of character
    for(int i = 0; i< s.length(); i++){
        char ch = s[i];

        //lower case
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }

    //find maximum occ char
    int maxi = -1, ans = 0;
    
    for(int i = 0; i < 26; i++){
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
        maxi = max(maxi, arr[i]);
    }   

    char finalAns = 'a' + ans;    //spoon feeding
    return finalAns;
}

int main(){
    string s;
    cout << "Enter string : " ; 
    cin >> s;
    cout << "Maximum Occuring char is : " << maxOccuring(s) <<endl;
} 