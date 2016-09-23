#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

void displayVector(vector<int> V) {
	for(vector<int>::iterator it = V.begin(); it != V.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
}

void displayAdjacencyList(map<int, vector<int> > &AdjacencyList) {
	for(map<int, vector<int> >::iterator it = AdjacencyList.begin(); it != AdjacencyList.end(); it++) {
		cout<<it->first<<"->";
		displayVector(it->second);
	}
}

void printShortestDistances(int root, vector<int>& distance) {
	for(int i = 0;i<distance.size();i++) {
		if(distance[i] == INT_MAX)
			cout<<"Distance::Root("<<root<<")->Vertex("<<i<<"): INF"<<endl;
		else
			cout<<"Distance::Root("<<root<<")->Vertex("<<i<<"): "<<distance[i]<<endl;		
	}	
}

void printParents(vector<int>& parent) {
	for(int i = 0;i<parent.size();i++)
		cout<<"Vertex("<<i<<")->Parent: "<<parent[i]<<endl;
}

void BFS(map<int, vector<int> >& AdjacencyList, int root, int vertexCount) {
	queue<int> BFSqueue;
	vector<bool> visited(vertexCount, false);
	vector<int> distance(vertexCount, INT_MAX);
	vector<int> parent(vertexCount, -1);
	BFSqueue.push(root);
	visited[root] = true;
	distance[root] = 0;
	while(!BFSqueue.empty()) {
		int currentVertex = BFSqueue.front();
		BFSqueue.pop();
		cout<<currentVertex<<" ";
		for(vector<int>::iterator it = AdjacencyList[currentVertex].begin(); it != AdjacencyList[currentVertex].end(); it++) {
			if(!visited[*it]) {
				visited[*it] = true;
				parent[*it] = currentVertex;
				distance[*it] = 1 + distance[currentVertex];
				BFSqueue.push(*it);
			}
		}
	}
	cout<<"\n\nprintParents()\n";
	printParents(parent);
	cout<<"\nprintShortestDistances()\n";
	printShortestDistances(root, distance);
	cout<<"-------------------------------\n";
}
int main() {
	int edgeCount, vertexCount;
	cout<<"Enter the number of vertices: ";
	cin>>vertexCount;
	cout<<"Enter the number of edges: ";
	cin>>edgeCount;
	if(edgeCount) {
		cout<<"Vertices should be 0 indexed please!. Enter edges (from to): \n";
		int from, to;
		map<int, vector<int> > AdjacencyList;
		while(edgeCount--) {
			cin>>from>>to;
			AdjacencyList[from].push_back(to);
		}
		cout<<"\ndisplayAdjacencyList()\n";
		displayAdjacencyList(AdjacencyList);
		cout<<"BFS and shortest distance from each node to all other nodes is displayed below: \n";
		for(map<int, vector<int> >::iterator it = AdjacencyList.begin(); it != AdjacencyList.end(); it++) { 
			cout<<"-------------------------------\n";
			cout<<"BFS("<<it->first<<") :";
			BFS(AdjacencyList, it->first, vertexCount);
			cout<<endl;
		}

	}
	return 0;
}