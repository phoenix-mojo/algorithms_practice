#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	void displayVector(vector<int>& myVector) {
		for(vector<int>::iterator it = myVector.begin();it!=myVector.end();++it){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	bool recurse(vector<char>& s, vector<char>& t) {
		if(!s.size())
    		return true;
    	bool result;
    	int i;
    	//displayVector(s);
    	//displayVector(t);
    	for(i = 0;i<t.size();i++) {
    		if(s[0] == t[i]) {
    			result = true;
    			break;
    		}
    	}
    	if(!result)
    		return false;
    	s.erase(s.begin());
    	//cout<<"i: "<<i<<endl;
    	if(i<t.size()) {
    		t.erase(t.begin(), t.begin()+i+1);
    		//cout<<"inner t: ";
    		//displayVector(t);
        	return result = recurse(s, t);
    	}
    	else
    		return false;
	}
    bool isSubsequence(string s, string t) {
    	vector<char>sVector (s.begin(), s.end());
    	vector<char>tVector (t.begin(), t.end());
    	return recurse(sVector, tVector);
    	
    }

    bool iterativeIsSubsequence(string s, string t) {
    	bool result = true;
    	int i=0, j=0;
    	while(i<s.length()) {
    		while(j<t.length()) {
    			//cout<<"s[i]: "<<s[i]<<" t[j]: "<<t[j]<<endl;
    			if(s[i] == t[j]) {
    				i++;
    			}
    			j++;
    		}
    		if(i != s.length()) {
    			result = false;
    			break;
    		}
    	}
    	return result;
    }

    int binarySearch(vector<int> & myVector, int left, int right, int searchMe) {
    	if(left>right) {
    		if(right<0)
    			return 0;
    		else
    			return right + 1;
    	}
    	int mid = (left + right)/2;
    	if(myVector[mid] == searchMe)
    		return mid;
    	if(myVector[mid]>searchMe)
    		return binarySearch(myVector, left, mid-1, searchMe);
    	else
    		return binarySearch(myVector, mid+1, right, searchMe);
    }

    void displayMap(map<char, vector<int> >& hashCharOccurences) {
    	map<char, vector<int> >::iterator it;
    	for(it=hashCharOccurences.begin();it != hashCharOccurences.end();it++) {
    		cout<<it->first<<"->";
    		displayVector(it->second);
		}
		cout<<"--------------"<<endl;
    }

    void initializeMap(map<char, vector<int> >& hashCharOccurences, string t) {
    	for(int i=0;i<t.size();i++)
    		hashCharOccurences[t[i]].push_back(i);
    }

    bool binarysearchIsSubsequence(string s, string t) {
    	map<char, vector<int> > hashCharOccurences;
    	int prevPos = -1;
    	initializeMap(hashCharOccurences, t);
    	//displayMap(hashCharOccurences);
    	for(int i=0;i<s.size();i++) {
    		if(hashCharOccurences.find(s[i]) == hashCharOccurences.end())
    			return false;
    		if(hashCharOccurences[s[i]].empty())
    			return false;
 			int pos = binarySearch(hashCharOccurences[s[i]], 0, hashCharOccurences[s[i]].size()-1, prevPos);
 			if(prevPos>=0 && hashCharOccurences[s[i]][pos]<prevPos)
 				return false;
 			prevPos = hashCharOccurences[s[i]][pos];
 			hashCharOccurences[s[i]].erase(hashCharOccurences[s[i]].begin(), hashCharOccurences[s[i]].begin()+pos+1);
    	}
    	return true;
    }
};

int main() {
	Solution solution;

	string t, s;
	s = "abbbcab";
	t = "agvbbbcdfbaccb";
	bool resultRecursive = solution.isSubsequence(s, t);
	bool resultIterative = solution.iterativeIsSubsequence(s, t);
	bool resultBinarySearch = solution.binarysearchIsSubsequence(s, t);
	cout<<boolalpha<<resultRecursive<<endl;
	cout<<boolalpha<<resultIterative<<endl;
	cout<<boolalpha<<resultBinarySearch<<endl;
	return 0;
}