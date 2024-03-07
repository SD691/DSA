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
    ListNode* middleNode(ListNode* head) {
        ListNode* rab = head;
        ListNode* tou = head;

        while( rab->next!=NULL && rab->next->next!=NULL){
            rab = rab->next->next;
            tou = tou->next;
        }
        if(rab->next==NULL){
            return tou;
        }
        return tou->next;
        
    }
};