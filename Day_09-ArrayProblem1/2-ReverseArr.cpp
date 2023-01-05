#include<iostream>
using namespace std;

void reverese(int arr[], int size) {
	int start = 0;
	int end = size-1; 
	while (start < end)
		swap(arr[start++], arr[end--]);
}	

int main() {
	
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
    cout << "Reversed array is" << endl;
	reverese(arr, 7);
	//print array
	for(int i = 0; i < 7; i++){
		cout << arr[i]  <<" " ;
	}
	cout << endl;

}
