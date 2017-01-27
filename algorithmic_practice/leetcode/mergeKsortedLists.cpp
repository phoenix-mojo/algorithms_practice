/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
typedef pair<int, int> P;
 
class Solution {
public:
    /*
    Use a min-priority Q to push heads of each list initially.
    Then push only the head of one which was popped from the Q this time (the minimum value) and moved to result list
    Do this until the Q is not empty.
    Reason for using a pair -> want to keep track of index of the head list which was popped.
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<P, vector<P>, greater<P> > sorted_heads;
        ListNode *res = NULL, *rear = NULL, *this_list_head = NULL;
        int push_next_time = -1;
        while (1) {
            if (push_next_time == -1) {
                for (int i = 0; i < lists.size(); i++) {
                    this_list_head = lists[i];
                    
                    if (this_list_head != NULL) {
                        sorted_heads.push(make_pair(this_list_head->val, i));
                    }
                }
            }
            else {
                this_list_head = lists[push_next_time];
                if (this_list_head != NULL) {
                        sorted_heads.push(make_pair(this_list_head->val, push_next_time));
                    }
            }
            if (sorted_heads.empty())
                break;
            if (res == NULL) {
                res = new ListNode(sorted_heads.top().first);
                rear = res;
            }
            else {
                ListNode *temp = new ListNode(sorted_heads.top().first);
                rear->next = temp;
                rear = rear->next;
            }
            if (lists[sorted_heads.top().second] != NULL) {
                lists[sorted_heads.top().second] = lists[sorted_heads.top().second]->next;
                push_next_time = sorted_heads.top().second;
            }
            sorted_heads.pop();
        }
        return res;
    }
};