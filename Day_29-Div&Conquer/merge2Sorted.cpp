#include<iostream>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int ans[]){
	int i = 0, j = 0, k = 0;
	
	// Traverse both array
	while (i<n1 && j <n2){
		if (arr1[i] < arr2[j])
			ans[k++] = arr1[i++];
		else
			ans[k++] = arr2[j++];
	}
    //element pending rha gya to
	while (i < n1)
		ans[k++] = arr1[i++];

	while (j < n2)
		ans[k++] = arr2[j++];
}

int main()
{
	int arr1[] = {1, 3, 5, 7};
	int n1 = 4;

	int arr2[] = {2, 3, 6, 8};
	int n2 = 4;

	int ans[n1+n2];
	mergeArrays(arr1, arr2, n1, n2, ans);

	cout << "Array after merging" <<endl;
	for (int i=0; i < n1+n2; i++)
		cout << ans[i] << " ";

	return 0;
}
