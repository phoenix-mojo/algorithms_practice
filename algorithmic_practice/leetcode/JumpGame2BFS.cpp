#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:

	/*void displayAdjacencyList(map<int, vector<int> > &AdjacencyList) {
		for(map<int, vector<int> >::iterator it = AdjacencyList.begin(); it != AdjacencyList.end(); it++) {
			cout<<it->first<<"->";
			displayVector(it->second);
		}
	}
	void displayVector(vector<int> V) {
		for(vector<int>::iterator it = V.begin(); it != V.end(); it++)
			cout<<*it<<" ";
		cout<<endl;
	}

	int BFS(map<int, vector<int> >& AdjacencyList, int root, int destination) {
		queue<int> BFSqueue;
		vector<bool> visited(destination+1, false);
		vector<int> distance(destination+1, INT_MAX);
		vector<int> parent(destination+1, -1);
		BFSqueue.push(root);
		visited[root] = true;
		distance[root] = 0;
		while(!BFSqueue.empty()) {
			int currentVertex = BFSqueue.front();
			BFSqueue.pop();
			for(vector<int>::iterator it = AdjacencyList[currentVertex].begin(); it != AdjacencyList[currentVertex].end(); it++) {
				if(!visited[*it]) {
					visited[*it] = true;
					parent[*it] = currentVertex;
					distance[*it] = 1 + distance[currentVertex];
					BFSqueue.push(*it);
				}
			}
		}
		return distance[destination];
	}


    int jump(vector<int>& nums) {
    	if(!nums.size())
    		return 0;
    	map<int, vector<int> >AdjacencyList;
    	for(int i =0;i<nums.size();i++) {
    		for(int j=1;j<=nums[i];j++) {
    			if(j+i<nums.size()) {
    				AdjacencyList[i].push_back(j+i);
    			}
    			else goto esc;
    		}
    	}
    	esc:
    	return BFS(AdjacencyList, 0, nums.size()-1) == INT_MAX ? -1 : BFS(AdjacencyList, 0, nums.size()-1);
    }*/

	int jump(vector<int>& nums) {
		if(!nums.size())
			return 0;
		if(nums.size() == 1 && nums[0] == 0)
			return -1;
		queue<int>BFSqueue;
		vector<bool> visited(nums.size(), false);
		vector<int>distance(nums.size(), INT_MAX);
		BFSqueue.push(0);
		visited[0] = true;
		distance[0] = 0;
		while(!BFSqueue.empty()) {
			int currentVertex = BFSqueue.front();
			BFSqueue.pop();
			for(int i = 1;i<=nums[currentVertex];i++) {
				if(!visited[i+currentVertex]) {
					visited[i+currentVertex] = true;
					distance[i+currentVertex] = 1 + distance[currentVertex];
					if(currentVertex+i>=nums.size()-1)
						return distance[nums.size()-1] == INT_MAX ? -1 : distance[nums.size()-1];
					BFSqueue.push(i+currentVertex);
				}
			}
		}
		return -1;		
	}
};

int main() {
	int tc, size, input;
	cin>>tc;
	while(tc--) {
		vector<int> nums;
		cin>>size;
		while(size--) {
			cin>>input;
			nums.push_back(input);
		}
		Solution solver;
		cout<<solver.jump(nums)<<endl;
	}
	return 0;
}