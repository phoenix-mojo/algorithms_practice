#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

ListNode* createListFromArray(int arr[], int arr_size) {
	ListNode *head = NULL;
	ListNode *rear = NULL;
	for(int i=0;i<arr_size;i++) {
		ListNode* newNode = new ListNode();
		newNode->val = arr[i];
		newNode->next = NULL;
		if(head != NULL){
			rear->next = newNode;
			rear = newNode;
		}
		else {
			head = newNode;
			rear = head;
		}
	}
	return head;
}

void displayList(ListNode* head) {
	while(head!=NULL) {
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}
 
class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *result_head = NULL;
    	ListNode *result_rear = NULL;
    	int carry = 0;
    	while(l1 != NULL && l2 != NULL) {
			ListNode *result_newNode = new ListNode();
			result_newNode->val = (l1->val + l2->val + carry)%10;
			result_newNode->next = NULL;
			carry = (l1->val + l2->val + carry)/10;
			if(result_head != NULL) {
				result_rear->next = result_newNode;
				result_rear = result_newNode;
			}
			else {
				result_head = result_newNode;
				result_rear = result_head;
			}
			l1 = l1->next;
			l2 = l2->next;
    	}
    	while(l2 != NULL) {
    		ListNode *result_newNode = new ListNode();
			result_newNode->val = (l2->val + carry)%10;
			result_newNode->next = NULL;
			carry = (l2->val + carry)/10;
			if(result_head != NULL) {
				result_rear->next = result_newNode;
				result_rear = result_newNode;
			}
			else {
				result_head = result_newNode;
				result_rear = result_head;
			}
			l2 = l2->next;
    	}
    	while(l1 != NULL) {
    		ListNode *result_newNode = new ListNode();
			result_newNode->val = (l1->val + carry)%10;
			result_newNode->next = NULL;
			carry = (l1->val + carry)/10;
			if(result_head != NULL) {
				result_rear->next = result_newNode;
				result_rear = result_newNode;
			}
			else {
				result_head = result_newNode;
				result_rear = result_head;
			}
			l1 = l1->next;
    	}
    	if(carry != 0) {
    		ListNode *result_newNode = new ListNode();
    		result_newNode->val = carry;
    		result_newNode->next = NULL;
    	}
    	return result_head;
    }
};

int main() {
	int input1[] = {2,4,5,5,6,7};
	int input2[] = {5,6,4,1,2,3,6};
	ListNode* l1 = createListFromArray(input1, 6);
	ListNode* l2 = createListFromArray(input2, 7);
	displayList(l1);
	displayList(l2);
	Solution obj;
	ListNode* result_list = obj.addTwoNumbers(l1, l2);
	displayList(result_list);
}