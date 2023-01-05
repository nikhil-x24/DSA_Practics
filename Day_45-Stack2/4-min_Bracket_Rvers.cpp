#include<iostream>
#include<stack>
using namespace std;

int countMinReversals(string s){

	int temp = 0, res = 0, n = s.size();
	if (n % 2 != 0)
		return -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '{')
			temp++;
		else {
			if (temp == 0) {
				res++;
				temp++;
			}
			else
				temp--;
		}
	}
	if (temp > 0)
		res += temp / 2;
	return res;
}

int main(){
	string expr = "}}{{";
	cout << countMinReversals(expr);
	return 0;
}
