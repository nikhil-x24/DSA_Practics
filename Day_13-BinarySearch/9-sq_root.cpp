#include<iostream>
using namespace std;

int squareRoot(int n){
    int s = 0;
    int e = n;
    int mid  = (s+e) / 2;
    int ans = -1;
    
    while(s<=e){
        int sqaure = mid *mid;

        if(sqaure == n){
            return mid;
        }
        if(sqaure < n){
            ans = mid;
            s = mid + 1;
        }
        if(sqaure > n){
            e = mid - 1;
        }
        mid = (s+e) /2;
    }
    return ans;
}
//find floating point
double morePre(int n, int precision, int tempsol){
    double factor = 1;
    double ans = tempsol;
    for(int i = 0; i < precision; i++){
        factor = factor /10;
        for(double j = ans; j * j < n; j = j+ factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n = 37;
    int tempsol = squareRoot(n);
    cout <<"Ans is : " <<  morePre(n, 3, tempsol);
}