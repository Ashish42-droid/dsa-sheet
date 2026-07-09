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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(-1);
        ListNode*merge = dummy;
        while(a!=nullptr && b!=nullptr){
            if (a->val <=b->val){
                merge->next = a;
                a=a->next;
            }
             else {
                merge->next = b;
                b=b->next;
            }
            merge= merge->next;
        
        
    }
    if (a!=nullptr) merge->next=a;
        else merge->next=b;
    return dummy->next;
    }
};