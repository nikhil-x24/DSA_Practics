#include <bits/stdc++.h>
using namespace std;

// Recursive function to print the valid combinations
// s is string, st is resultant string
void printCompRec(const string& s, int index,
				int max_index, string st)
{
	// if the end of the string is reached
	if (index == max_index) {
		cout << st << "\n";
		return;
	}

	// push the current character to result
	st.push_back(s[index]);

	// recur for the next [Using Char]
	printCompRec(s, index + 1, max_index, st);

	// remove the character from result
	st.pop_back();

	// set count of digits to 1
	int count = 1;

	// addition the adjacent digits
	if (!st.empty()) {

		if (isdigit(st.back())) {

			// get the digit and increase the count
			count += (int)(st.back() - '0');

			// remove the adjacent digit
			st.pop_back();
		}
	}

	// change count to a character
	char to_print = (char)(count + '0');

	// add the character to result
	st.push_back(to_print);

	// recur for this again [Using Count]
	printCompRec(s, index + 1, max_index, st);
}

// Wrapper function
void printComb(std::string s)
{
	// if the string is empty
	if (!s.length())
		return;

	// Stores result strings one by one
	string st;

	printCompRec(s, 0, s.length(), st);
}

// driver function
int main()
{
	string str = "nik";
	printComb(str);
	return 0;
}
