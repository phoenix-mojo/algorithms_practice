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
    ListNode* removeDuplicates(ListNode* head) {
    	ListNode* result = head;
    	if(head == NULL)
			return head;
    	while(head->next != NULL) {
            if(head->val == head->next->val) {
                ListNode* temp = head->next;
                head->next = head->next->next;
                delete(temp);
            }
            else
            	head = head->next;
        }
        return result;
    }
};

int main() {
	int input1[] = {};
	ListNode* l1 = createListFromArray(input1, 0);
	displayList(l1);
	Solution obj;
	ListNode* result_list = obj.removeDuplicates(l1);
	displayList(result_list);
}