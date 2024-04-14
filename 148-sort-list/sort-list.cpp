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
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next = left;
                temp=temp->next;
                left=left->next;
            }
            else{
                temp->next = right;
                temp=temp->next;
                right = right->next;
            }
        }

        while(left){
            temp->next = left;
            temp=temp->next;
            left=left->next;
        }
        while(right){
            temp->next = right;
            temp=temp->next;
            right = right->next;
        }
        return dummy->next;
    }
    ListNode* mergeSort(ListNode* temp){
        if(temp==NULL || temp->next==NULL) return temp;
        ListNode* mid = middle(temp);
        ListNode* r = mid->next;
        mid->next = NULL;
        ListNode* left = mergeSort(temp);
        ListNode* right = mergeSort(r);

        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};