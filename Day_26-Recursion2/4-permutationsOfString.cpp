#include<iostream>
using namespace std;

void permute(string a, int s, int e){
	// Base case
	if (s == e)
		cout << a <<endl;

	else{
		// Permutations
		for (int i = s; i <= e; i++){
			// Swapping done
			swap(a[s], a[i]);

			//RR
			permute(a, s+1, e);

			//backtrack
			swap(a[s], a[i]);
		}
	}
}

int main(){
	string str = "abc";
	int n = str.size();
	permute(str, 0, n-1);
	return 0;
}
