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
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;

    queue<TreeNode*> q;
    q.push(root);
    bool ltr = true;

    while (!q.empty()) {
        int lvl = q.size();
        vector<int> temp;

        while (lvl--) {
            TreeNode* t = q.front();
            q.pop();
            temp.push_back(t->val);          // ALWAYS push_back, no first/last needed

            if (t->left)  q.push(t->left);
            if (t->right) q.push(t->right);
        }

        if (!ltr) reverse(temp.begin(), temp.end());   // flip only when needed
        res.push_back(temp);
        ltr = !ltr;
    }
    return res;
}
};