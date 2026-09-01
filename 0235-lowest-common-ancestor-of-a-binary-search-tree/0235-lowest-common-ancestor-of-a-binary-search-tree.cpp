/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  using  node =TreeNode ;
         node * ans = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
 
        if (p->val < q -> val){
        fun (root ,p ,q);}
        else{
              fun (root ,q, p);}
              return ans;
    }

    void fun (node *root , node*a , node *b){
        if (root == nullptr)
        return;
        if (root == a || root == b ){
        ans = root ;
        return ;}
        if (root -> val < a->val)
        fun (root -> right,a,b);
        else if (root -> val > b->val)
        fun (root -> left,a,b);
        else
        ans = root ;

    }
};