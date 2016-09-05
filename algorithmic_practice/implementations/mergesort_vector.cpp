#include<iostream>
#include<vector>

using namespace std;

void displayVector(vector<int> myVector) {
	for(vector<int>::iterator it = myVector.begin();it!=myVector.end();++it){
		cout<<*it<<" ";
	}
	cout<<endl;
}

vector<int> mergeSplits(vector<int>& left, vector<int>& right) {
	vector<int> resultVector;
	vector<int>::iterator leftTracker = left.begin(), rightTracker = right.begin();
	while(leftTracker != left.end() && rightTracker != right.end()) {
		if(*leftTracker<=*rightTracker) {
			resultVector.push_back(*leftTracker);
			leftTracker++;
		}
		else {
			resultVector.push_back(*rightTracker);
			rightTracker++;
		}
	}
	while(leftTracker != left.end()) {
		resultVector.push_back(*leftTracker);
		leftTracker++;
	}
	while(rightTracker != right.end()) {
		resultVector.push_back(*rightTracker);
		rightTracker++;
	}
	return resultVector;
}

vector<int> mergeSort(vector<int>& myVector) {
	if(myVector.size()<=1)
		return myVector;
	vector<int>leftVector (myVector.begin(), myVector.begin()+(myVector.size()/2));
	vector<int>rightVector (myVector.begin()+(myVector.size()/2), myVector.end());
	leftVector = mergeSort(leftVector);
	rightVector = mergeSort(rightVector);
	myVector = mergeSplits(leftVector, rightVector);
	return myVector;
}	

int main() {
	vector<int> myVector;
	int size, input;
	cin>>size;
	cout<<"Input array:\n";
	for(int i=0;i<size;i++) {
		cin>>input;
		myVector.push_back(input);
	}
	myVector = mergeSort(myVector);
	cout<<"Sorted array:\n";
	displayVector(myVector);
	return 0;
}