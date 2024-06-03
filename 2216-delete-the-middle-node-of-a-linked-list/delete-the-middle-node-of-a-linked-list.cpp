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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        if(count==1)return NULL;

        count = count/2;
        count = count;

        int counting = 0;
        ListNode* slow = head;
        while(counting != count-1){
            counting++;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;


    }
};