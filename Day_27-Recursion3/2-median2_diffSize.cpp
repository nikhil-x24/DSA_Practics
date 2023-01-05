#include<iostream>
using namespace std;

int getMedian(int ar1[], int ar2[], int n, int m){
	int i = 0; 
	int j = 0; 
	int count;
	int m1 = -1, m2 = -1;
	/*loop till (m+n)/2*/
	for (count = 0; count <= (m + n)/2; count++){
		//store (n+m)/2-1 in m2
		m2=m1;
		if(i != n && j != m){
			m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
		}
		else if(i < n){
			m1 = ar1[i++];
		}
		// for case when j<m,
		else{
			m1 = ar2[j++];
		}
	}
	
	if((m + n) % 2 == 1){
		return m1;
	}
	else{
		return (m1+m2)/2;
	}
}

int main(){
	int ar1[] = {900};
	int ar2[] = {5,8,10,20};
	int n1 = 1;
	int n2 = 4;
	cout <<"Median :-> " << getMedian(ar1, ar2, n1, n2);
}

