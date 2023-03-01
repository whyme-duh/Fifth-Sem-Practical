#include <bits/stdc++.h>
using namespace std;
#define max 10
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i
		= (low - 1); 
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
	int arr[max],n,i ;
    cout<<"Enter the number of items to be sorted: (Quick Sort)"<<endl;
    cin>>n;
    cout<<"Enter the numbers to be sorted"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
