#include<iostream>
#include<vector>
using namespace std;

void findCombinations(vector<char> keypad[],
					  int input[], string res, int index, int n){

	if (index == n) {
		cout << res <<endl;
		return;
	}

	// Stores current digit
	int digit = input[index];

	// Size of the list corresponding to current digit
	int len = keypad[digit].size();

	// One by one replace the digit with each character in the
	// corresponding list and recur for next digit
	for (int i = 0; i < len; i++) {
		findCombinations(keypad, input,   res+keypad[digit][i], 
		                 index + 1, n);
	}
}

int main(){
	vector<char> keypad[] =
	{
		{}, {},	 // 0 and 1 digit don't have any characters associated
		{ 'a', 'b', 'c' },
		{ 'd', 'e', 'f' },
		{ 'g', 'h', 'i' },
		{ 'j', 'k', 'l' },
		{ 'm', 'n', 'o' },
		{ 'p', 'q', 'r', 's'},
		{ 't', 'u', 'v' },
		{ 'w', 'x', 'y', 'z'}
	};

	int input[] = {2, 3};
	int n = 2;
	findCombinations(keypad, input, string(""), 0, n );
	return 0;
}
