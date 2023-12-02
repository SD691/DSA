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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> vec;
        if(!list2 && !list1) return NULL;
        while(list1!=nullptr){
            vec.push_back(list1->val);
            list1= list1->next;
        }

        while(list2!=nullptr){
            vec.push_back(list2->val);
            list2= list2->next;
        }

        sort(vec.begin(),vec.end());
        ListNode* crnptr;
        ListNode* head;

        for(int i=0; i<vec.size(); i++){
            ListNode* ptr = new ListNode();
            ptr->val = vec[i];
            if(i==0){
                head = ptr;
                crnptr = head;
            }
            else{
                crnptr->next = ptr;
                crnptr = crnptr->next;
            }
        }
        return head;
    }
};