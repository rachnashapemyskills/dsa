// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];
//	cout<<"\n Pivot "<<pivot;


	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		
		cout<<"\n arr ["<<i<<"] = "<<arr[i]<<"\n";
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	cout<<"\n Pivot Index = "<<pivotIndex;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);
	cout<<"\n after Left \n";
	for (int i = start; i < p-1; i++) {
		cout <<"\n" <<arr[i] << " ";
	}
	// Sorting the right part
	quickSort(arr, p + 1, end);
	cout<<"\n after Right \n";

	for (int i = p+1; i < end; i++) {
		cout <<"\n"<< arr[i] << " ";
	}
}

int main()
{

	int arr[] = { 9, 3, 4, 2, 1, 8 };
	int n = 6;
	cout<<"\n Before Sorting \n";
		for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout<<"\n*********************************\n";
	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

