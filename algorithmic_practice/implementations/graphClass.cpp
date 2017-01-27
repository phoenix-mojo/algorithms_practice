#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Graph {
public:
	unordered_map <int, vector<int> > adjacencyList;
	int numVertices;
	int numEdges;
	Graph() {
		numVertices = 0;
		numEdges = 0;
		adjacencyList.clear();
	}

	void displayAdjacencyList(unordered_map <int, vector<int> >& adjacencyList) {
		for(unordered_map <int, vector<int> >::iterator it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
			cout<<it->first<<"->";
			displayVector(it->second);
		}
	}

	void createGraph() {
		int from, to;
		cout<<"Enter total vertices:";
		cin>>numVertices;
		cout<<"Enter 0 indexed edge pair [from] [to], terminate with -1 -1:\n";
		while (1) {
			cin>>from>>to;
			if (from == -1 && to == -1)
				break;
			numEdges++;
			adjacencyList[from].push_back(to);
		}
		cout<<"Graph created..\n";
		cout<<"Total vertices: "<<numVertices<<endl;
		cout<<"Total edges: "<<numEdges<<endl;
		cout<<"Displaying adjacency list for the graph..:\n";
		displayAdjacencyList(adjacencyList);
	}

	void BFS(int root) {
		cout<<"BFS from vertex: "<<root<<endl;
		queue<int> bfs;
		vector<bool>visited(numVertices, false);
		bfs.push(root);
		visited[root] = true;
		while(!bfs.empty()) {
			root = bfs.front();
			cout<<root<<" ";
			bfs.pop();
			for (int i = 0; i < adjacencyList[root].size(); i++)
				if (!visited[adjacencyList[root][i]]) {
					visited[adjacencyList[root][i]] = true;
					bfs.push(adjacencyList[root][i]);
				}
		}
		cout<<endl;
	}

	void DFS(int root) {
		cout<<"DFS from vertex: "<<root<<endl;
		vector<bool>visited(numVertices, false);
		DFSrecurse(root, visited);
	}

	void connectedComponents() {
		vector<bool>visited(numVertices, false);
		int components = 0;
		cout<<"\nPerform DFS to get connected components\n";
		for (int i = 0; i < numVertices; i++) {
			if (visited[i] == false) {
				components++;
				DFSrecurse(i, visited);
			}
		}
		cout<<"\nNumber of connected components: "<<components<<endl;
	}

	void topologicalSort() {
		vector<bool>visited(numVertices, false);
		stack<int> topologicalOrder;
		cout<<"\nPerform DFS to get topological sorting\n";
		for(int i = 0; i < numVertices; i++) {
			if (visited[i] == false)
				topologicalSortRecurse(i, visited, topologicalOrder);
		}
		cout<<"Topological Ordering: ";
		while (!topologicalOrder.empty()) {
			cout<<topologicalOrder.top()<<" ";
			topologicalOrder.pop();
		}
		cout<<endl;
	}

private:
	void displayVector(vector<int> display) {
		for(vector<int>::iterator it = display.begin(); it != display.end(); it++)
			cout<<*it<<" ";
		cout<<endl;
	}
	void DFSrecurse(int root, vector<bool>& visited) {
		visited[root] = true;
		cout<<root<<" ";
		for (int i = 0; i < adjacencyList[root].size(); i++)
			if (!visited[adjacencyList[root][i]])
				DFSrecurse(adjacencyList[root][i], visited);
	}

	void topologicalSortRecurse(int root, vector<bool>& visited, stack<int>& topologicalOrder) {
		visited[root] = true;
		for (int i = 0; i < adjacencyList[root].size(); i++)
			if (!visited[adjacencyList[root][i]])
				topologicalSortRecurse(adjacencyList[root][i], visited, topologicalOrder);
		topologicalOrder.push(root);
	}
};

int main() {
	Graph myGraph;
	myGraph.createGraph();
	myGraph.BFS(0);
	myGraph.DFS(0);
	myGraph.connectedComponents();
	myGraph.topologicalSort();
	return 0;
}