#include <iostream>
#include <unordered_map>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* createListFromArray(int arr[], int arr_size) {
    ListNode *head = NULL;
    ListNode *rear = NULL;
    for(int i=0;i<arr_size;i++) {
        ListNode* newNode = new ListNode(arr[i]);
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
    ListNode* deleteDuplicates(ListNode* head) {
    unordered_map<int, bool> track_dups;
    ListNode* bp = head;
    if (bp == NULL)
        return bp;
    while (head->next != NULL) {
        if (head->val == head->next->val)
            track_dups[head->val] = true;
        head = head->next;
    }
    head = bp;
    bool leave_last = false;
    while (head != NULL) {
        if (track_dups.find(head->val) != track_dups.end()) {
            if (head->next == NULL) {
                //ListNode* dummy = new  ListNode(-12);
                //head->next = dummy;
                leave_last = true;
                break;
            }
            ListNode* temp = head->next;
            head->val = temp->val;
            head->next = temp->next;
            delete(temp);
        }
        else {
            head = head->next;
        }
    }
    if (leave_last) {
        head = bp;
        if (head->next != NULL) {
            while (head->next->next != NULL)
            head = head->next;
        ListNode* temp = head->next;
        head->next = NULL;
        if (temp != NULL)
            delete(temp);
        }
        else bp = NULL;
        
    }
    return bp; 
    }
};

int main() {
    int input1[] = {};
    ListNode* l1 = createListFromArray(input1, 0);
    displayList(l1);
    Solution obj;
    ListNode* result_list = obj.deleteDuplicates(l1);
    displayList(result_list);
}