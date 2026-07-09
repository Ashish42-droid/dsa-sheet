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

    class Node{
    public:
        int value;
        ListNode* ptr;

        Node(int v,ListNode* p){
            value=v;
            ptr=p;
        }
    };

    struct Compare{
        bool operator()(const Node &a,const Node &b){
            return a.value>b.value;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<Node,vector<Node>,Compare> pq;

        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
                pq.push({lists[i]->val,lists[i]});
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;

        while(!pq.empty())
        {
            Node temp=pq.top();
            pq.pop();

            tail->next=temp.ptr;
            tail=tail->next;

            if(temp.ptr->next!=NULL)
            {
                pq.push({temp.ptr->next->val,temp.ptr->next});
            }
        }

        return dummy->next;
    }
};