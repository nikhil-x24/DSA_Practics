#include<iostream>
#include<vector>
using namespace std;

void reverseWords(string s){
	
	vector<string> tmp;
	string str = "";

	for (int i = 0; i < s.length(); i++){
		
		if (s[i] == ' '){
			tmp.push_back(str);
			str = "";
		}
		else
			str += s[i];
	}
	// Last word remaining,add it to vector
	tmp.push_back(str);

	// Now print from last to first in vector
	for (int i = tmp.size() - 1; i > 0; i--)
		cout << tmp[i] << " ";
	// Last word remaining,print it
	cout << tmp[0] << endl;
}

int main()
{
	string s = "My name is Nikhil verma";
	reverseWords(s);
	return 0;
}
