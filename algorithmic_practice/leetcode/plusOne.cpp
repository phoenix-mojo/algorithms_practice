#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       	vector<int>::iterator vec_it;
       	int carry = 1;
       	vector<int> res;
       	reverse(digits);
       	for (vec_it = digits.begin(); vec_it != digits.end(); vec_it++) {
       		res.push_back(((*vec_it + carry) % 10));
       		carry =  (*vec_it + carry > 9) ? 1 : 0;
       	}
       	if (carry == 1)
       		res.push_back(1);
       	reverse(res);
       	return res;
    }
    void reverse(vector<int>& digits) {
    	vector<int>::iterator vec_it;
    	vector<int>::reverse_iterator vec_it2;
    	int temp;
    	for (vec_it = digits.begin(), vec_it2 = digits.rbegin(); vec_it != digits.begin() + digits.size()/2; vec_it++, vec_it2++) {
    		temp = *vec_it;
    		*vec_it = *vec_it2;
    		*vec_it2 = temp;
    	}
    }
    void display(vector<int>& digits) {
    	vector<int>::iterator vec_it;
    	for (vec_it = digits.begin(); vec_it != digits.end(); vec_it++)
    		cout<<*vec_it;
    	cout<<endl;
    }
};

int main() {
	Solution s;
	vector<int> digits, res;
	int dig, ip;
	cin>>dig;
	while (dig--) {
		cin>>ip;
		digits.push_back(ip);
	}
	res = s.plusOne(digits);
	s.display(res);
	return 0;
}