/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* hare = head;
        ListNode* tour = head;

        if(head == NULL) return 0;
        while( hare!=NULL && hare->next!=NULL && tour!=NULL && tour->next!=NULL && tour->next->next!=NULL){
            if(hare->next == tour->next->next) return 1;
            hare = hare->next;
            tour= tour->next->next;
        }
        return false;
    }
};