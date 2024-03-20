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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
       a = a-1;
       b = b+1;
        ListNode* head = list1;
        ListNode* temp=list1;
        ListNode* temp2=list1;
        while(a>0){
            temp = temp->next;
            a--;
        }
        while(b>0){
            temp2 = temp2->next;
            b--;
        }

        temp->next = list2;
        temp = temp->next;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        if(temp2!=NULL){
            temp->next = temp2;
        }
        return head;

    }
};