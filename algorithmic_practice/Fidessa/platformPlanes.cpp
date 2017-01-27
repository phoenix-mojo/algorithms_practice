#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int minPlat(vector<int>& arrive, vector<int>& depart) {
	sort (arrive.begin(), arrive.end());
	sort (depart.begin(), depart.end());
	int arrive_ctr = 1, depart_ctr = 0, plat_ctr = 1, min_plats = 1;
	while (arrive_ctr < arrive.size() && depart_ctr < depart.size()) {
		if (arrive[arrive_ctr] <= depart[depart_ctr]) {
			arrive_ctr++;
			plat_ctr++;
			if (min_plats < plat_ctr)
				min_plats = plat_ctr;
		}
		else {
			depart_ctr++;
			plat_ctr--;
		}
	}
	return min_plats;
}

int main() {
	vector<int> arrive, depart;
	int sz, ip;
	cin>>sz;
	for (int i = 0; i < sz; i++) {
		cin>>ip;
		arrive.push_back(ip);
	}
	for (int i = 0; i < sz; i++) {
		cin>>ip;
		depart.push_back(ip);
	}
	cout<<minPlat(arrive, depart)<<endl;
	return 0;

}