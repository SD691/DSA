/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    struct sort_fun{
        bool operator() (ListNode* x, ListNode* y){
            bool flag = true;
            if(x->val > y->val) flag = true;
            else flag = false;

            return flag; 
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, sort_fun> pq;

        for (int i = 0; i < lists.size(); i++) {
    ListNode* it = lists[i];
    while (it != NULL) {
        pq.push(new ListNode(it->val));  // Create a new instance for each node
        it = it->next;
    }
}


        ListNode* head = NULL;
        ListNode* temp = NULL;

        while(!pq.empty()){
            if(head==NULL){
                head = pq.top();
                temp = head;
                pq.pop();
            }
            else{
                temp->next = pq.top();
                temp = temp->next;
                pq.pop();
            }
        }
        return head;
    }
    
};