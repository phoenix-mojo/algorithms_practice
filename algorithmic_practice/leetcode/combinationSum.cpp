#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
	void displayVector(vector<vector<int> >& results) {
		for(vector<vector<int> >::iterator it = results.begin(); it!= results.end(); it++) {
			for(vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
				cout<<*it2<<" ";
			cout<<endl;
		}
	}

	void displayMap(map<int, vector<vector<int> > >& myMap) {
		for(map<int, vector<vector<int> > >::iterator it = myMap.begin(); it != myMap.end(); it++) {
			cout<<it->first<<"->";
			displayVector(it->second);
		}

	}

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    	sort(candidates.begin(), candidates.end());
    	map<int, vector<vector<int> > > myMap;
    	for(int i=1;i<=target;i++) {
        	for(vector<int>::iterator it = candidates.begin();it != candidates.end() && *it<=i;it++) {
    			if(i == *it) {
    				vector<int> element;
    				element.push_back(i);
    				myMap[i].push_back(element);
    			}
    			else {
    				if(myMap.find(i-*it) != myMap.end()) {
    					for(vector<vector<int> >::iterator it2=myMap[i-*it].begin(); it2 != myMap[i-*it].end(); it2++) {
    						if(*it<=*(it2)->begin()) {
    							vector<int> element2;
    							element2.push_back(*it);
    							for(vector<int>::iterator it3=it2->begin(); it3 != it2->end();it3++)
    								element2.push_back(*it3);
    							myMap[i].push_back(element2);
    						}
    						
    					}    					

        			} 
    			} 
        	}
        }
        return myMap[target];
    }
};

int main() {
	Solution solve;
	int size, target, input;
	vector<int> candidates;
	vector<vector<int> > result;
	cin>>size;
	while(size-->0) {
		cin>>input;
		candidates.push_back(input);
	}
	cin>>target;
	result = solve.combinationSum(candidates, target);
	solve.displayVector(result);
	return 0;

}