#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct treeNode {
	int data;
	treeNode *left;
	treeNode *right;
};

struct treeNode *createNode(int data) {
	treeNode *node = new treeNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void displayQ(queue<pair<treeNode *, int> > verticals) {
	pair<treeNode *, int> nodeAndLevel;
	while(!verticals.empty()) {
		nodeAndLevel = verticals.front();
		cout<<nodeAndLevel.first->data<<" "<<nodeAndLevel.second<<endl;
		verticals.pop();
	}
}

void displayVerticalTraversal(map<int, vector<int> > &v_traversal) {
	map<int, vector<int> >::iterator map_iter;
	vector<int>::iterator vect_iter;
	for (map_iter = v_traversal.begin(); map_iter != v_traversal.end(); map_iter++) {
		for (vect_iter = map_iter->second.begin(); vect_iter != map_iter->second.end(); vect_iter++)
			cout<<*vect_iter<<" ";
		cout<<endl;
	}
}

void displayTreeTopView(map<int, vector<int> > &v_traversal) {
	map<int, vector<int> >::iterator map_iter;
	for (map_iter = v_traversal.begin(); map_iter != v_traversal.end(); map_iter++) {
			cout<<map_iter->second.front()<<" ";
	}
}

void treeTopView(struct treeNode *node) {
	queue<pair<treeNode *, int> > verticals;
	map<int, vector<int> > v_traversal;
	pair<treeNode *, int> nodeAndLevel;
	if (node == NULL)
		return;
	verticals.push(make_pair(node, 0));
	while (!verticals.empty()) {
		nodeAndLevel = verticals.front();
		v_traversal[nodeAndLevel.second].push_back(nodeAndLevel.first->data);
		verticals.pop();
		if (nodeAndLevel.first->left != NULL) {
			verticals.push(make_pair(nodeAndLevel.first->left, nodeAndLevel.second - 1));
		}
		if (nodeAndLevel.first->right != NULL) {
			verticals.push(make_pair(nodeAndLevel.first->right, nodeAndLevel.second + 1));
		}
	}
	cout<<"\nVerticalTraversal:\n";
	displayVerticalTraversal(v_traversal);
	cout<<"TopView:\n";
	displayTreeTopView(v_traversal);
}

void preOrder(struct treeNode *node) {
	if (node == NULL)
		return;
	cout<<node->data<<" ";
	preOrder(node->left);
	preOrder(node->right);
}

int main() {
	treeNode *node = createNode(1);
	node->left = createNode(2);
	node->right = createNode(3);
	node->left->left = createNode(4);
	node->left->right = createNode(5);
	node->right->left = createNode(6);
	node->right->right = createNode(7);
	node->right->left->right = createNode(8);
	node->right->right->right = createNode(9);
	cout<<"PreOrder:\n";
	preOrder(node);
	treeTopView(node);
	return 0;
}