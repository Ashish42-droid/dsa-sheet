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
    using Node= TreeNode;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
         bool check = false;
         int sum= 0;
         fun(root,targetSum,sum,check);
         return check;
    }
    void fun(Node*root,int targetSum,int sum,bool &check){
       if (root==nullptr)
       return ;
       sum += root->val;
       if (root->left==nullptr && root->right==nullptr){
        if (sum==targetSum){
            check = true;
            return ;
        }
       }
       fun (root ->left,targetSum,sum,check);
       fun (root->right,targetSum,sum,check);
       return ;

    }
};