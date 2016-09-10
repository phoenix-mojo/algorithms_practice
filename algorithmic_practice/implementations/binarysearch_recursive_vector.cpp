#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& myVector, int left, int right, int searchElement) {
	if(left>right)
		return -1;
	else {
		int mid = left + (right - left)/2;
		if(myVector[mid] == searchElement)
			return mid;
		else if(myVector[mid]>searchElement)
			return(binarySearch(myVector, left, mid-1, searchElement));
		else
			return(binarySearch(myVector, mid+1, right, searchElement));
	}
	
}

int main() {
	vector<int> myVector;
	int size, input, searchElement;
	cin>>size;
	cout<<"Input array: \n";
	while(size-->0) {
		cin>>input;
		myVector.push_back(input);
	}
	cout<<"Input search element: \n";
	cin>>searchElement;
	int res = binarySearch(myVector, 0, myVector.size()-1, searchElement);
	(res == -1) ? cout<<"Search element not found.\n" : cout<<"Search element found at position: "<<res<<endl; 
	return 0;
}