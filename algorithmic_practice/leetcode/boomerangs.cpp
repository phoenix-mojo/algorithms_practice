#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int> >& points) {
    	map<int, int> distances;
    	map<int, int>::iterator map_it;
    	int res = 0;
    	vector<pair<int, int> >::iterator vec_it1, vec_it2;
    	for (vec_it1 = points.begin(); vec_it1 != points.end(); vec_it1++) {
    		distances.clear();
    		for (vec_it2 = points.begin(); vec_it2 != points.end(); vec_it2++) {
    			if (vec_it1 != vec_it2)
    				distances[distance(*vec_it1, *vec_it2)]++;
    		}
    		for (map_it = distances.begin(); map_it != distances.end(); map_it++) {
    			res += (map_it->second * (map_it->second - 1));
    		}
    	}
    	return res;
    }
    int distance(pair<int, int> pt1, pair<int, int> pt2) {
    	int p1_x, p1_y, p2_x, p2_y;
    	p1_x = pt1.first;
    	p1_y = pt1.second;
    	p2_x = pt2.first;
    	p2_y = pt2.second;
    	return (p1_x - p2_x) * (p1_x - p2_x) + (p1_y - p2_y) * (p1_y - p2_y);
    }
};

int main() {
	vector<pair<int, int> > points;
	int tot_pt, ip1, ip2;
	cin>>tot_pt;
	while (tot_pt--) {
		cin>>ip1>>ip2;
		points.push_back(make_pair(ip1, ip2));
	}
	Solution s;
	cout<<s.numberOfBoomerangs(points)<<endl;
	return 0;
}