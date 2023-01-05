//Minimum platform problem - GFG
#include<iostream>
#include<algorithm>
using namespace std;

int maxPlatform(int arr[], int dep[], int n){
    //sort
    sort(arr, arr+n);
    sort(dep, dep+n);

    int i = 1;
    int j = 0;

    int plateform = 1;
    int maxi = INT_MIN;

    while(i < n && j < n){
        
        if(arr[i] <= dep[j])
            plateform++;

        else if(arr[i] > dep[j])
            plateform--;

        i++;
        j++;
        maxi = max(maxi, plateform);
    }
    return maxi;
}

int main(){
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1120, 1130, 1200, 1900, 2000};
    int n = 6;
    cout << maxPlatform(arr, dep, n) << endl;
}