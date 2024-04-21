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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }

        if(count == n){
            return head->next;
        }
        count = count - n-1;
        ListNode* slow = head;
        while(count){
            slow = slow->next;
            count--;
        }
        if(slow->next->next!=NULL){
            slow->next = slow->next->next;
        }
        else{
            slow->next = NULL;
        }
        return head;
        

    }
};