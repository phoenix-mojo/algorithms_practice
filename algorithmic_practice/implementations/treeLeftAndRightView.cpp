#include <iostream>
#include <map>
#include <vector>

using namespace std;


/****** Tree fills ********/
struct treeNode {
	int data;
	struct treeNode *left;
	struct treeNode *right;
};

struct treeNode *createNode(int data) {
	treeNode *node = new treeNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
/****** Tree fills ********/

/****** Left View *********/
void leftView(struct treeNode *node, int level, int *max_level) {
	if (node == NULL)
		return;
	if (*max_level < level) {
		*max_level = level;
		cout<<node->data<<" ";
	}
	leftView(node->left, level + 1, max_level);
	leftView(node->right, level + 1, max_level);
}
/****** Left View *********/

/****** Right View ********/
void rightView(struct treeNode *node, int level, int *max_level) {
	if (node == NULL)
		return;
	if (*max_level < level) {
		*max_level = level;
		cout<<node->data<<" ";
	}
	rightView(node->right, level + 1, max_level);
	rightView(node->left, level + 1, max_level);
}
/****** Right View ********/

int main() {
	int max_level = 0;
	/*

		    1
			/\
		   2  3
		  /\  /\
		 4	5 6 7
			   \ \
			   	8 9	

	*/
	struct treeNode* node = createNode(1);
	node->left = createNode(2);
	node->right = createNode(3);
	node->left->left = createNode(4);
	node->left->right = createNode(5);
	node->right->left = createNode(6);
	node->right->right = createNode(7);
	node->right->left->right = createNode(8);
	node->right->right->right = createNode(9);
	cout<<"LeftView: ";
	leftView(node, 1, &max_level);
	cout<<"\nRightView: ";
	max_level = 0;
	rightView(node, 1, &max_level);
	return 0;
}