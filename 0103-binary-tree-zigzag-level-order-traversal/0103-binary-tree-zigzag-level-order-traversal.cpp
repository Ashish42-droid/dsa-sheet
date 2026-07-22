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
    using Node=TreeNode;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if (root == nullptr)
        return res;       
        
        queue<Node*>q;
        q.push(root);
        bool ltr=0;
        while(!q.empty()){
            int lvl = q.size();
            int first = 0;
            int last = lvl -1;
            vector<int> temp(lvl);
            while(lvl--){
                Node* t = q.front();
                q.pop();
                if (ltr==0){
                temp[first]= t->val;
                first++;
                }
                else{
                temp[last]=t->val;
                last--;
                }
                if (t->left!=nullptr)
                q.push(t->left);
                if (t->right!=nullptr)
                q.push(t->right);


            }
            res.push_back(temp);
            ltr= ltr-1;
        }
        return res;
    }
};