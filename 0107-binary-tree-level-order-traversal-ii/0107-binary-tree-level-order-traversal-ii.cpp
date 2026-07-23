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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
           vector<vector<int>>res;
        if ( root == nullptr) return res;
     
        queue<node*> q;
        q.push(root);
        while(!q.empty()){
            int lvl = q.size();
            vector<int> temp;
            while(lvl--){
                node *t = q.front();
                q.pop();
                temp.push_back(t->val);
                if (t->left != nullptr)
                q.push(t->left);
                if (t->right != nullptr)
                q.push(t->right);

            

            }
                  res.push_back(temp);
        }
                 reverse (res.begin(),res.end());
                 return res ;
            }
};