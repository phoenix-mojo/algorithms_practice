#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

};

TreeNode* createNode(int data) {
	TreeNode* node = new TreeNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void inOrder(struct TreeNode* node) {  // Left Root Right
	if(node == NULL)
		return;
	inOrder(node->left);
	cout<<node->data<<" ";
	inOrder(node->right);
}
void preOrder(struct TreeNode* node) { //Root Left Right
	if(node == NULL)
		return;
	cout<<node->data<<" ";
	preOrder(node->left);
	preOrder(node->right);
}
void postOrder(struct TreeNode* node) { //Left Right Root
	if(node == NULL)
		return;
	postOrder(node->left);
	postOrder(node->right);
	cout<<node->data<<" ";
}

void printLevel(TreeNode* node, int level) {
	if(level<1 || node == NULL)
		return;
	if(level == 1)
		cout<<node->data<<" ";
	printLevel(node->left, level-1);
	printLevel(node->right, level-1);
}

void levelOrder(TreeNode* node) {
	queue<TreeNode*> treeQueue;
	if(node == NULL)
		return;
	treeQueue.push(node);
	while(!treeQueue.empty()) {
		node = treeQueue.front();
		cout<<node->data<<" ";
		treeQueue.pop();
		if(node->left != NULL)
			treeQueue.push(node->left);
		if(node->right != NULL)
			treeQueue.push(node->right);
	}
}

int treeHeight(TreeNode* node) {
	return (node == NULL) ? 0 : 1 + max(treeHeight(node->left), treeHeight(node->right));
}

void levelOrderLineByLine(TreeNode* node) {
	if(node == NULL)
		return;
	queue <TreeNode*> treeQueue;
	int levelCounter;
	treeQueue.push(node);
	while(!treeQueue.empty()) {
		levelCounter = treeQueue.size();
		while(levelCounter--) {
			node = treeQueue.front();
			treeQueue.pop();
			cout<<node->data<<" ";
			if(node->left != NULL)
				treeQueue.push(node->left);
			if(node->right != NULL)
				treeQueue.push(node->right);
		}
		cout<<endl;
	}
}

void printLevelOrderSpiral(TreeNode* node) {
	queue<TreeNode*> treeQueue;
	stack<TreeNode*> treeStack;
	bool flip = true;
	if(node == NULL)
		return;
	treeQueue.push(node);
	while(!treeQueue.empty()) {
		int counter = treeQueue.size();
		while(counter--) {
			node = treeQueue.front();
			treeQueue.pop();
			if(node->left != NULL)
				treeQueue.push(node->left);
			if(node->right != NULL)
				treeQueue.push(node->right);
			if(flip) {
				treeStack.push(node);
			}
			else {
				cout<<node->data<<" ";
			}
		}
		if(flip) {
			while(!treeStack.empty()) {
				cout<<treeStack.top()->data<<" ";
				treeStack.pop();
			}
		}
		flip = !flip;
		cout<<endl;
	}
}

void displayStack(stack<TreeNode*> treeStack) {
	while(!treeStack.empty()) {
		cout<<"*"<<treeStack.top()->data<<" ";
		treeStack.pop();
	}
		
	cout<<endl;
}
void inOrderWithoutRecursion(TreeNode* node) {
	if(node == NULL)
		return;
	stack<TreeNode*> treeStack;
	while(!treeStack.empty() || node) {
		if(node != NULL) {
			treeStack.push(node);
			node = node->left;
		}
		else {
			node = treeStack.top();
			treeStack.pop();
			cout<<node->data<<" ";
			node = node->right;
		}
	}
}

void preOrderWithoutRecursion(TreeNode* node) {
	if(node == NULL)
		return;
	stack<TreeNode*> treeStack;
	treeStack.push(node);
	while(!treeStack.empty()) {
		node = treeStack.top();
		cout<<node->data<<" ";
		treeStack.pop();
		if(node->right != NULL)
			treeStack.push(node->right);
		if(node->left != NULL)
			treeStack.push(node->left);
	}
}

void postOrderWithoutRecursionTwoStacks(TreeNode* node) {
	if(node == NULL)
		return;
	stack<TreeNode*> first;
	stack<TreeNode*> second;
	first.push(node);
	while(!first.empty()) {
		node = first.top();
		first.pop();
		second.push(node);
		if(node->left != NULL)
			first.push(node->left);
		if(node->right != NULL)
			first.push(node->right);
	}
	while(!second.empty()) {
		cout<<second.top()->data<<" ";
		second.pop();
	}
}

int treeSize(TreeNode* node) {
	return (node == NULL) ? 0 : 1 + treeSize(node->left) + treeSize(node->right);
}

bool checkIdenticalTrees(TreeNode* node1, TreeNode* node2) {
	if(node1 == NULL && node2 == NULL)
		return true;
	if(node1 == NULL || node2 == NULL)
		return false;
	return (node1->data == node2->data) && checkIdenticalTrees(node1->left, node2->left) && checkIdenticalTrees(node1->right, node2->right);
}

void deleteTree(TreeNode* node) {
	if(node == NULL)
		return;
	deleteTree(node->left);
	deleteTree(node->right);
	delete(node);
}

int indexOfNodeInTree(vector<int> Nodes, int searchElement, int left, int right) {
	int index = 0;
	for(int i = left; i<= right; i++) {
		if(Nodes[i] == searchElement) {
			index = i;
			break;
		}
	}
	return index;
}
	

TreeNode* generateTreeFromInOrderAndPostOrder(vector<int> inOrder, vector<int> postOrder, int left, int right) {
	if(left>right)
		return NULL;
	static int postOrderIndex = postOrder.size()-1;
	TreeNode* node = createNode(postOrder[postOrderIndex--]);
	if(left == right)
		return node;
	int inOrderIndex = indexOfNodeInTree(inOrder, node->data, left, right);
	node->right = generateTreeFromInOrderAndPostOrder(inOrder, postOrder, inOrderIndex+1, right);
	node->left = generateTreeFromInOrderAndPostOrder(inOrder, postOrder, left, inOrderIndex-1);
	return node;
}

TreeNode* generateTreeFromInOrderAndPreOrder(vector<int> inOrder, vector<int> preOrder, int left, int right) {
	if(left>right)
		return NULL;
	static int preOrderIndex = 0;
	TreeNode* node = createNode(preOrder[preOrderIndex++]);
	if(left == right)
		return node;
	int inOrderIndex = indexOfNodeInTree(inOrder, node->data, left, right);
	//cout<<left<<" "<<right<<" "<<node->data<<" "<<inOrderIndex<<endl;
	node->left = generateTreeFromInOrderAndPreOrder(inOrder, preOrder, left, inOrderIndex-1);
	node->right = generateTreeFromInOrderAndPreOrder(inOrder, preOrder, inOrderIndex+1, right);
	return node;
}

void displayVector(vector<int> V) {
	for(vector<int>::iterator it = V.begin(); it != V.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
}

bool checkIfSumExiststoLeavesRecurse(TreeNode* node, int sum, vector<int> path) {
	int my_sum = 0;
	bool flag = false;
	if(node == NULL) {
		return false;
	}
	path.push_back(node->data);
	if(node->left == NULL && node->right == NULL) {
		for(int i=0; i<path.size();i++)
			my_sum+=path[i];
		path.clear();
		if(my_sum == sum)
			flag = true;
	}
	if(flag)
		return true;
	else {		
		return(checkIfSumExiststoLeavesRecurse(node->left, sum, path) || 
		checkIfSumExiststoLeavesRecurse(node->right, sum, path));
	}
}

bool checkIfSumExiststoLeaves(TreeNode* node, int sum)
{
	vector<int> empty;
	return checkIfSumExiststoLeavesRecurse(node, sum, empty);
}

void printAllPathsToLeaves(TreeNode* node, vector<int> path) {
	if(node == NULL)
		return;
	path.push_back(node->data);
	if(node->left == NULL && node->right == NULL) {
		displayVector(path);
		path.clear();
	}
	else {
		printAllPathsToLeaves(node->left, path);
		printAllPathsToLeaves(node->right, path);
	}
}

bool checkChildrenSumProperty(TreeNode* node) {
	if(node == NULL || (node->left == NULL && node->right == NULL))
		return true;
	bool curr_result;
	if(node->left == NULL)
		curr_result = node->data == node->right->data ? true : false;
	else if(node->right == NULL)
		curr_result = node->data == node->left->data ? true : false;
	else
		curr_result = node->data == node->left->data + node->right->data ? true : false;
	return (curr_result && checkChildrenSumProperty(node->left) && checkChildrenSumProperty(node->right));
}

void enforceChildrenSumProperty(TreeNode* node) {
	if(node == NULL || (node->left == NULL && node->right == NULL))
		return;
	enforceChildrenSumProperty(node->left);
	enforceChildrenSumProperty(node->right);
	if(node->left == NULL && !(node->right->data == node->data)) {
		if(node->data > node->right->data)
			node->right->data = node->data;
		else
			node->data = node->right->data;
	}
	else if(node->right == NULL && !(node->left->data == node->data)) {
		if(node->data > node->left->data)
			node->left->data = node->data;
		else
			node->data = node->left->data;
	}
	else if(!(node->data == node->left->data + node->right->data)){
		if(node->data < node->left->data + node->right->data)
			node->data = node->left->data + node->right->data;
		else {
			node->left->data = node->data - node->right->data;
			enforceChildrenSumProperty(node->left);
		}
	}
}

int main() {

	/*

		    1
			/\
		   2  3
		  /\  /\
		 4	5 6 7
		/
	   8
	  /
	 9 	

	*/
	TreeNode* node = createNode(1);
	node->left = createNode(2);
	node->right = createNode(3);
	node->left->left = createNode(4);
	node->left->right = createNode(5);
	node->right->left = createNode(6);
	node->right->right = createNode(7);
	node->left->left->left = createNode(8);
	node->left->left->left->left = createNode(9);
	cout<<"PreOrder()\n";
	preOrder(node);
	cout<<"\nInorder()\n";
	inOrder(node);
	cout<<"\nPostOrder()\n";
	postOrder(node);
	cout<<"\nLevel(1)\n";
	printLevel(node, 1);
	cout<<"\nLevel(2)\n";
	printLevel(node, 2);
	cout<<"\nLevel(3)\n";
	printLevel(node, 3);
	cout<<"\nlevelOrder()\n";
	levelOrder(node);
	cout<<"\nlevelOrderLineByLine()\n";
	levelOrderLineByLine(node);
	cout<<"\ninOrderWithoutRecursion()\n";
	inOrderWithoutRecursion(node);
	cout<<"\npreOrderWithoutRecursion()\n";
	preOrderWithoutRecursion(node);
	cout<<"\npostOrderWithoutRecursionTwoStacks()\n";
	postOrderWithoutRecursionTwoStacks(node);
	cout<<"\nTreeHeight\n";
	cout<<treeHeight(node);
	cout<<"\nTreeSize\n";
	cout<<treeSize(node);
	cout<<"\nIdenticalTrees()\n";
	cout<<boolalpha<<checkIdenticalTrees(node, node);
	TreeNode* node2 = createNode(1);
	node2->left = createNode(2);
	node2->right = createNode(3);
	node2->left->left = createNode(4);
	node2->left->right = createNode(5);
	node2->right->left = createNode(6);
	node2->right->right = createNode(7);
	node2->left->left->left = createNode(8);
	node2->left->left->left->left = createNode(9);
	TreeNode* node3 = createNode(1);
	node3->right = createNode(2);
	node3->left = createNode(3);
	node3->left->left = createNode(4);
	node3->left->right = createNode(5);
	cout<<"\nIdenticalTrees()\n";
	cout<<boolalpha<<checkIdenticalTrees(node, node2);
	cout<<"\nIdenticalTrees()\n";
	cout<<boolalpha<<checkIdenticalTrees(node2, node3);
	cout<<"\nDeleteTree()\n";
	deleteTree(node2);
	cout<<"\nDeleteTree()\n";
	deleteTree(node3);
	int arr1[] = {9, 8, 4, 2, 5, 1, 6, 3, 7};
	int arr2[] = {9, 8, 4, 5, 2, 6, 7, 3, 1};
	int arr3[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
	vector<int>inOrderVector;
	vector<int>postOrderVector;
	vector<int>preOrderVector;
	inOrderVector.assign(arr1, arr1+9);
	postOrderVector.assign(arr2, arr2+9);
	preOrderVector.assign(arr3, arr3+9);
	cout<<"\ngenerateTreeFromInOrderAndPostOrder()\n";
	node2 = generateTreeFromInOrderAndPostOrder(inOrderVector, postOrderVector, 0, postOrderVector.size()-1);
	cout<<"\npreOrder()\n";
	preOrder(node2);
	cout<<"\nIdenticalTrees()\n";
	cout<<boolalpha<<checkIdenticalTrees(node, node2);
	cout<<"\ngenerateTreeFromInOrderAndPreOrder()\n";
	TreeNode* generatedNode2 = generateTreeFromInOrderAndPreOrder(inOrderVector, preOrderVector, 0, preOrderVector.size()-1);
	cout<<"\npostOrder()\n";
	postOrder(generatedNode2);
	cout<<"\nIdenticalTrees()\n";
	cout<<boolalpha<<checkIdenticalTrees(node, generatedNode2);
	cout<<"\nprintAllPathsToLeaves()\n";
	vector<int> empty;
	printAllPathsToLeaves(node, empty);
	cout<<"\ncheckIfSumExiststoLeaves()\n";
	int my_sum = 11;
	cout<<boolalpha<<checkIfSumExiststoLeaves(node, my_sum)<<endl;
	cout<<"\nprintLevelOrderSpiral()\n";
	printLevelOrderSpiral(node);
	TreeNode* node4 = createNode(10);
	node4->left = createNode(8);
	node4->right = createNode(2);
	node4->left->left = createNode(3);
	node4->left->right = createNode(5);
	node4->right->left = createNode(2);
	cout<<"\ncheckChildrenSumProperty()\n";
	cout<<std::boolalpha<<checkChildrenSumProperty(node4)<<endl;
	TreeNode* node5 = createNode(50);
	node5->left = createNode(7);
	node5->right = createNode(2);
	node5->left->left = createNode(3);
	node5->left->right = createNode(5);
	node5->right->left = createNode(1);
	node5->right->right = createNode(30);
	cout<<"\nenforceChildrenSumProperty()\n";
	cout<<"\npreOrder();\n";
	preOrder(node5);
	enforceChildrenSumProperty(node5);
	cout<<"\npreOrder();\n";
	preOrder(node5);
	return 0;
}