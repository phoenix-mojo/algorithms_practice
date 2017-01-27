#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void displayV(vector<int>& v) {
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) 
		cout<<*it<<" ";
	cout<<endl;
}

bool checkOrdering(string ip, string ord) {
	unordered_map<char, vector<int> > freq;
	unordered_map<char, vector<int> >::iterator it;
	if (ord.size() == 0 || ord.size() == 1)
		return true;
	for (int i = 0; i < ip.size(); i++) {
		freq[ip[i]].push_back(i);
	}
	for (int i = 0; i < ord.size() - 1; i++) {
		//cout<<ord[i]<<"->";
		//displayV(freq[ord[i]]);
		if (freq[ord[i]].empty() || freq[ord[i + 1]].empty())
				return false;
		if (freq[ord[i]].back() > freq[ord[i + 1]][0])
			return false;
	}
	return true;
}

int main() {
	string input, order;
	getline(cin, input);
	getline(cin, order);
	cout<<boolalpha<<checkOrdering(input, order)<<endl;
	return 0;
}