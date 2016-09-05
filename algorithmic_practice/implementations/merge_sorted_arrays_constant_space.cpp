#include<iostream>

using namespace std;

void inputArray(int arr[], int size) {
	for(int i =0;i<size;i++)
		cin>>arr[i];
}

void displayArray(int arr[], int size) {
	for(int i =0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

}

void mergeSortedArrays(int arr1[], int arr2[], int size1, int size2) {
	int j, i;
	for(j = size2-1;j>=0;j--) {
		int last = arr1[size1 -1];
		for(i = size1-1;i>=0 && arr1[i]>arr2[j];i--) {
			if(i != size1-1 || i != 0)
				arr1[i] = arr1[i-1];
		}
		if(i!=size1-1) {
			arr1[i+1] = arr2[j];
			arr2[j] = last;
		}
	}
}

int main() {
	int size1, size2, input, arr1[50], arr2[50];
	cin>>size1;
	inputArray(arr1, size1);
	cin>>size2;
	inputArray(arr2, size2);
	cout<<"Before merging:\n";
	cout<<"First array:\n";
	displayArray(arr1, size1);
	cout<<"Second array:\n";
	displayArray(arr2, size2);
	mergeSortedArrays(arr1, arr2, size1, size2);
	cout<<"After merging:\n";
	cout<<"First array:\n";
	displayArray(arr1, size1);
	cout<<"Second array:\n";
	displayArray(arr2, size2);
	return 0;
}