#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        cout<<"\n key is : "<<key;
        cout<<"\n j is : "<<j;
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];j = j - 1;
    }
    arr[j + 1] = key;
    cout<<"\n array[j+1] : "<<arr[j+1];
}
}
void printArray(int arr[], int n)
{
int i;
for (i = 0; i < n; i++)
cout << arr[i] << " ";
cout << endl;
}
int main()
{
	int n;
	cout<<"Enter the total elements : ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter array elements : ";
		cin>>arr[i];
		
	}
	insertionSort(arr,n);
	cout<<"\n";
	printArray(arr,n);
//	insertionSort(arr,n);
}
