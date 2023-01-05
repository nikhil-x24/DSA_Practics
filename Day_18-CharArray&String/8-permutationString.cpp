/*   i/p -> 
     S1 = {eidbaooo}
     S2 = {ab}
     {ab} ka permutation -> {ab} , {ba} 
     to {ba} S1 me hai....
*/
#include<iostream>
using namespace std;

bool checkEqual(int a[26], int b[26]){
     for(int i = 0; i < 26; i++){
          if(a[i] != b[i]){
               return 0;
          }
     }
     return 1;
}

bool checkInclusion(string s1, string s2){

     //character count array
     int cnt1[26] = {0};
     for(int i = 0; i < s1.length(); i++){
          int index = s1[i] - 'a';
          cnt1[index]++;
     }

     //now traverse s2 string in window of size s1 length and compare
     int i = 0;
     int windowSize = s1.length();
     int cnt2[26] = {0};

     //running for first window
     while(i< windowSize && i < s2.length()){
          int index = s2[i] - 'a';
          cnt2[index]++;
          i++;
     }

     if(checkEqual(cnt1, cnt2)){
          return 1;
     }
     //nhi to aagle window process kro
     while(i < s2.length()){
          char newChar = newChar - 'a';
          int index = newChar - 'a';
          cnt2[index]++;

          char oldChar = s2[i- windowSize];
          index = oldChar - 'a';
          cnt2[index]--;
          i++;

          if(checkEqual(cnt1, cnt2)){
               return 1;
          }
     }
     return 0;
}

int main(){
    string s2 = "eidbaooo";
    string s1 = "ie";
    cout << checkInclusion(s1, s2);
}