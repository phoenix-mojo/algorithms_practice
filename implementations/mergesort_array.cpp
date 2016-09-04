#include<iostream>
#include<vector>

using namespace std;

void displayVector(int arr[], int size) {
	for(int i=0;i<size;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void mergeSplits(int arr[], int left, int mid, int right) {
	int leftVector[mid-left+1];
	int rightVector[right-mid];
	for (int i = 0; i < mid-left+1; i++)
        leftVector[i] = arr[left + i];
    for (int j = 0; j < right-mid; j++)
        rightVector[j] = arr[mid + 1+ j];
	int leftSize = mid-left+1, rightSize = right-mid, leftTracker = 0, rightTracker = 0, myVectorTracker = left;
	while(leftTracker<leftSize && rightTracker<rightSize) {
		if(leftVector[leftTracker]<=rightVector[rightTracker]) {
			arr[myVectorTracker] = leftVector[leftTracker];
			leftTracker++;
			myVectorTracker++;
		}
		else {
			arr[myVectorTracker] = rightVector[rightTracker];
			rightTracker++;
			myVectorTracker++;
		}
	}
	while(leftTracker<leftSize) {
		arr[myVectorTracker] = leftVector[leftTracker];
		leftTracker++;
		myVectorTracker++;
	}
	while(rightTracker<rightSize) {
		arr[myVectorTracker] = rightVector[rightTracker];
		rightTracker++;
		myVectorTracker++;
	}
}

void splitAndMerge(int arr[], int left, int right) {
	if(left<right) {
		int mid = (left + right)/2;
		splitAndMerge(arr, left, mid);
		splitAndMerge(arr, mid+1, right);
		mergeSplits(arr, left, mid, right);
	}
}

void mergeSort(int arr[], int size) {
	splitAndMerge(arr, 0, size);
}

int main() {
	int arr[50];
	int size, input;
	cin>>size;
	for(int i=0;i<size;i++)
		cin>>arr[i];
	mergeSort(arr, size-1);
	displayVector(arr, size);
	return 0;
}