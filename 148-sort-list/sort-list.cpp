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
    ListNode* sortList(ListNode* head) {
        vector<int> temp;
        while(head){
            temp.push_back(head->val);
            head = head->next;
        }
        sort(temp.begin(),temp.end());
        ListNode* dummy = new ListNode(-1);
        ListNode* tempp = dummy;
        for(int i=0; i<temp.size(); i++){
            ListNode* node = new ListNode(temp[i]);
            dummy->next = node;
            dummy = dummy->next;
        }
        return tempp->next;
    }
};