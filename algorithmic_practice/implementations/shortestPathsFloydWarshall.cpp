#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<climits>

using namespace std;

void displayPairVector(vector<pair<int, int> > display) {
	for(vector<pair<int, int> >::iterator it = display.begin(); it != display.end(); it++)
		cout<<"("<<it->first<<", "<<it->second<<")";
	cout<<endl;
}

void displayVector(vector<int> display) {
	for(vector<int>::iterator it = display.begin(); it != display.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
}

void displayAdjacencyList(map <int, vector<pair<int, int> > >& adjacencyList) {
	for(map <int, vector<pair<int, int> > >::iterator it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
		cout<<it->first<<"->";
		displayPairVector(it->second);
	}
}

void displayDistanceMatrix(vector<vector<int> >& distanceMatrix) {
	for(vector<vector<int> >::iterator it = distanceMatrix.begin(); it != distanceMatrix.end(); it++) {
		displayVector(*it);
		cout<<endl;
	}
	cout<<endl;
}

void AddEdgeToGraph(map <int, vector<pair<int, int> > >& adjacencyList, int from, int to, int weight) {
	adjacencyList[from].push_back(make_pair(to, weight));
}

void floydWarshall(map <int, vector<pair<int, int> > >& adjacencyList, vector<vector<int> >& distanceMatrix) {
	for(map<int, vector<pair<int, int> > >::iterator it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
		distanceMatrix[it->first][it->first] = 0;
		for(vector<pair<int, int> >::iterator it2=adjacencyList[it->first].begin();it2 != adjacencyList[it->first].end(); it2++)
			distanceMatrix[it->first][it2->first] = it2->second;
		/*for(map<int, vector<pair<int, int> > >::iterator it3 = adjacencyList.begin(); it3 != adjacencyList.end(); it3++) {
			for(map<int, vector<pair<int, int> > >::iterator it4 = adjacencyList.begin(); it4 != adjacencyList.end(); it4++) {
				if(distanceMatrix[it3->first][it4->first] > distanceMatrix[it3->first][it->first] + distanceMatrix[it->first][it4->first])
					distanceMatrix[it3->first][it4->first] = distanceMatrix[it3->first][it->first] + distanceMatrix[it->first][it4->first];
			}
		}*/
	}
	for(int k=0;k<adjacencyList.size();k++) {
		for(int i=0;i<adjacencyList.size();i++) {
			for(int j=0;j<adjacencyList.size();j++) {
				if((distanceMatrix[i][k] != INT_MAX && distanceMatrix[k][j] != INT_MAX) && distanceMatrix[i][k]+distanceMatrix[k][j]<distanceMatrix[i][j])
					distanceMatrix[i][j]=distanceMatrix[i][k]+distanceMatrix[k][j];
			}
		}
	}

}

int main() {
	map<int, vector<pair<int, int>  > > adjacencyList;
	int numEdges, edgeLeft, edgeRight, weight;
	cout<<"Number of edges: ";
	cin>>numEdges;
	cout<<"Input edges (from, to, weight): \n";
	while(numEdges--) {
		cin>>edgeLeft>>edgeRight>>weight;
		AddEdgeToGraph(adjacencyList, edgeLeft, edgeRight, weight);
	}
	cout<<"Display adjacency list: \n";
	displayAdjacencyList(adjacencyList);
	vector<vector<int> > distanceMatrix (adjacencyList.size(), vector<int>(adjacencyList.size(), INT_MAX));
	floydWarshall(adjacencyList, distanceMatrix);
	cout<<"Display distance Matrix: \n";
	displayDistanceMatrix(distanceMatrix);
	return 0;
}