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

    void reverse(ListNode* s, ListNode* e){
        ListNode* curr = s;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL && k==1){
            return head;
        }

        ListNode* s=head;
        ListNode* e=head;
        int val = k-1;
        while(val){
            if(e->next==NULL){
                return head;
            }
            e=e->next;
            val--;
        }

        ListNode* root = reverseKGroup(e->next,k);
        e->next=NULL;
        reverse(s,e);
        s->next = root;
        return e;
    }
};