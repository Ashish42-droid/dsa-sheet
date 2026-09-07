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
public:
    using node = TreeNode;
    bool res = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
      fun ( root,0,targetSum);
      return res;  
    }
    bool fun (node *root,int sum,int targetSum){
        if (root== nullptr)
        return false;
        sum+=root->val;
        if (root->left==nullptr && root->right==nullptr){
            if (sum == targetSum)
            res = true;
            return res;
        }
    fun ( root->left,sum,targetSum);
    fun ( root->right,sum,targetSum);
    return res;
    }

};