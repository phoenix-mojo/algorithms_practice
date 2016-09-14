#include<iostream>
#include<vector>
#include<stack>
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


void recursiveDFS(int currentVertex, map <int, vector<int> >& adjacencyList, vector<bool>& visited) {
	cout<<currentVertex<<" ";
	visited[currentVertex] = true;
	for(vector<int>::iterator it = adjacencyList[currentVertex].begin(); it != adjacencyList[currentVertex].end(); it++) {
		if(!visited[*it])
			recursiveDFS(*it, adjacencyList, visited);
	}
	return;
}

void iterativeDFS(int origin, map <int, vector<int> >& adjacencyList, vector<bool>& visited) {
	stack<int> dfsStack;
	int currentVertex;
	dfsStack.push(origin);
	visited[origin] = true;
	while(!dfsStack.empty()) {
		currentVertex = dfsStack.top();
		dfsStack.pop();
		cout<<currentVertex<<" ";
		for(vector<int>::iterator it = adjacencyList[currentVertex].begin(); it != adjacencyList[currentVertex].end(); it++) {
			if(!visited[*it]) {
				visited[*it] = true;
				dfsStack.push(*it);
			}

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
	}
	cout<<"Display adjacency list: \n";
	displayAdjacencyList(adjacencyList);
	cout<<"DFS (recursive) results from all the vertices, one after the other displayed below: \n";
	for(map <int, vector<int> >::iterator it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
		cout<<"DFS recursive("<<it->first<<"): ";
		vector<bool>visited (adjacencyList.size(), false);
		recursiveDFS(it->first, adjacencyList, visited);
		cout<<endl;
	}
	cout<<"DFS (iterative) results from all the vertices, one after the other displayed below: \n";
	for(map <int, vector<int> >::iterator it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
		cout<<"DFS iterative("<<it->first<<"): ";
		vector<bool>visited (adjacencyList.size(), false);
		iterativeDFS(it->first, adjacencyList, visited);
		cout<<endl;
	}
	return 0;
}