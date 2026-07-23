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
    using node= TreeNode;
    public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
     int sum = 0;
     vector<vector<int>> res;
     vector<int> diary;
     fun (root,targetSum,sum,diary,res);
     return res;
    }

   void fun(node*root,int targetSum, int sum ,vector<int> &diary,vector<vector<int>> &res)
    {
        if (root == nullptr)
        return ;
        sum+= root->val;
         diary.push_back(root->val);
       
        if (root->left == nullptr && root ->right == nullptr){
            if (sum == targetSum){
               res.push_back(diary);
               diary.pop_back();
               return;

            }
        }

        fun (root->left,targetSum,sum,diary,res);
        fun (root->right,targetSum,sum,diary,res);
        diary.pop_back();
        return ;

    }
};