#include<iostream>
#include<vector>
#include<map>

using namespace std;

void displayVector(vector<int> display) {
	for(vector<int>::iterator it = display.begin(); it != display.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
}

void displayAdjacencyList(map <int, vector<int> >& adjacencyList) {
	for(map <int, vector<int> >::iterator it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
		cout<<it->first<<"->";
		displayVector(it->second);
	}
}

void AddEdgeToGraph(map <int, vector<int> >& adjacencyList, int from, int to) {
	adjacencyList[from].push_back(to);
}

void DFS(int currentVertex, map <int, vector<int> >& adjacencyList, vector<bool>& visited) {
	visited[currentVertex] = true;
	cout<<currentVertex<<" ";
	for(vector<int>::iterator it = adjacencyList[currentVertex].begin(); it != adjacencyList[currentVertex].end(); it++) {
		if(!visited[*it]) {
			visited[*it] = true;
			DFS(*it, adjacencyList, visited);
		}
	}
}
	

int main() {
	map<int, vector<int> > adjacencyList;
	int numEdges, edgeLeft, edgeRight;
	cout<<"Number of edges: ";
	cin>>numEdges;
	cout<<"Input edges (from, to): \n";
	while(numEdges--) {
		cin>>edgeLeft>>edgeRight;
		AddEdgeToGraph(adjacencyList, edgeLeft, edgeRight);
		AddEdgeToGraph(adjacencyList, edgeRight, edgeLeft);
	}
	cout<<"Display adjacency list: \n";
	displayAdjacencyList(adjacencyList);
	int components = 0;
	vector<bool> visited (adjacencyList.size(), false);
	for(map <int, vector<int> >::iterator it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
		if(visited[it->first] == false) {
			components++;
			cout<<"DFS("<<it->first<<"): ";
			DFS(it->first, adjacencyList, visited);
			cout<<endl;
		}	
	}
	cout<<"Total connected components: "<<components<<endl;
	return 0;
}