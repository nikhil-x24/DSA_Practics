#include <bits/stdc++.h>
using namespace std;

const int arr[] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 
                    1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 };

int countKeyPressed(string str, int len){
	int count = 0;

	// Count the key presses
	for (int i = 0; i < len; i++)
		count = count + arr[str[i] - 'a'];

	return count;
}

int main(){
	string str = "abcdef";
	int len = str.length();
	cout << countKeyPressed(str, len);

	return 0;
}
