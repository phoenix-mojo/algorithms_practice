#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map <char, int> freq_ran, freq_mag;
        map <char, int>::iterator map_it;
        for (int i = 0; i < ransomNote.length(); i++)
            freq_ran[ransomNote[i]]++;
        for (map_it == freq_ran.begin(); map_it != freq_ran.end(); map_it++)
            cout<<map_it->first<<" "<<map_it->second<<endl;
        for (int i = 0; i < magazine.length(); i++) 
            freq_mag[magazine[i]]++;
        for (map_it == freq_ran.begin(); map_it != freq_ran.end(); map_it++) {
            cout<<map_it->first<<" "<<map_it->second<<endl;
            if (map_it->second > freq_mag[map_it->first] || freq_mag.find(map_it->first) == freq_mag.end())
                return false;
        }
        return true;
        
    }
};

int main() {
	Solution solve;
	string r, m;
	cin>>r>>m;
	cout<<r<<endl;
	cout<<m<<endl;
	cout<<boolalpha<<solve.canConstruct(r, m)<<endl;
	return 0;
}