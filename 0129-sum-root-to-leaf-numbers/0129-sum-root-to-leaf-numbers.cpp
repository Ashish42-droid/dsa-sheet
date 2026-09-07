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
    int res = 0;
    int sumNumbers(TreeNode* root) {
         fun(root, 0);
        return res;
    }

    void fun (node* root, int sum) {
        if (root == nullptr) return ;

        sum = (sum)*10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
             res += sum;
            return;
        }

        fun(root->left, sum);
        fun(root->right, sum );

    }
};