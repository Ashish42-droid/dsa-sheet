/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    using node = TreeNode;
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int res = 0;
        fun (root,sum,res);
        return res;
    }
  void fun (node*root,int sum,int &res){
        if (root == nullptr)
        return ;
        sum= (sum* 10)+root->val;
         if (root ->left == nullptr && root ->right == nullptr){
                res +=sum;
                return ;
        }
        fun (root->left,sum,res);
        fun (root->right,sum,res);
         return ;
    }
};