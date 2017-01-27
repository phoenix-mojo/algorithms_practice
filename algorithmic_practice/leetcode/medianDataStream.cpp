#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class MedianFinder {
    priority_queue<long> max_prior;
    priority_queue<long, vector<long>, greater<long> > min_prior;
public:
    void addNum(int num) {
    	max_prior.push(num);
    	min_prior.push(max_prior.top());
    	max_prior.pop();
    	if (max_prior.size() < min_prior.size()) {
    		max_prior.push(min_prior.top());
    		min_prior.pop();
    	}

    }

    double findMedian() {
    	if (min_prior.size() == max_prior.size())
    		return (double(min_prior.top() + max_prior.top())/2);
    	else
    		return max_prior.top();
    }

    void display_min_prior() {
    	cout<<"Display min priority queue:\n";
    	while (!min_prior.empty()) {
    		cout<<min_prior.top()<<" ";
    		min_prior.pop();
    	}
    	cout<<endl;
    }
    void display_max_prior() {
    	cout<<"Display max priority queue:\n";
    	while (!max_prior.empty()) {
    		cout<<max_prior.top()<<" ";
    		max_prior.pop();
    	}
    	cout<<endl;
    }
};

int main() {
	MedianFinder mf;
	mf.addNum(7);
	cout<<"Current median: "<<mf.findMedian()<<endl;
	mf.addNum(3);
	cout<<"Current median: "<<mf.findMedian()<<endl;
	mf.addNum(8);
	cout<<"Current median: "<<mf.findMedian()<<endl;
	mf.addNum(6);
	cout<<"Current median: "<<mf.findMedian()<<endl;
	mf.addNum(2);
	cout<<"Current median: "<<mf.findMedian()<<endl;
	mf.addNum(9);
	cout<<"Current median: "<<mf.findMedian()<<endl;
	mf.display_min_prior();
	mf.display_max_prior();
	return 0;
}