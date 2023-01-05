#include<iostream>
using namespace std;
bool binary_search(int arr[][3], int n, int m, int row, int target){
    int s = 0;
    int e = m-1;
    int mid = s + (e-s) /2;

    while(s <= e){
        if(arr[row][mid] == target){
            cout <<"row " << row <<" "<<"col " << mid << endl;
            return true;
        }

        if(arr[row][mid] < target){
            s =mid +1;
        }
        else{
            e = mid -1;
        }
        mid = (s+e) /2;
    }
    return false;
}

bool search(int arr[][3], int n, int m, int target){
    //find row
    int s = 0;
    int e = n-1;
    int mid = (s+e) /2;

    while(s <= e){
        //checking starting element of row          -----------1
        if(arr[mid][0] == target){
            cout << mid << " " << 0 << endl;
            return true;
        }

        //check ending element of row      -----------2
        if(arr[mid][m-1] == target){
            cout << mid << " " << m-1 <<endl;
            return true;
        }
        
        //check if element is present in b/w start & end -----3
        if(target > arr[mid][0] && target < arr[mid][m-1]){
            //apply binary search
            bool ans = binary_search(arr, n, m, mid, target);
            return ans;
        }

        //check upper part    ---------------4
        if(target < arr[mid][0]){
            e = mid - 1;
        }
        //check lower part    ---------------5
        if(target > arr[mid][m-1]){
            s = mid + 1;
        }
        mid = (s+e) /2;
    }
    return false;
}

int main(){
    int arr[3][3] ={{1,  5,  9},   //row wise sorted  -> in short array sort 1,5,9,14,20,21,.........
                    {14, 20, 21},
                    {30, 34, 43}};

    int n = 3;
    int m = 3;
    int trgt = 34;
    cout << search(arr, n, m, trgt);
    return 0;
}