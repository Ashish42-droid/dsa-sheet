class Solution {
public:
    using node = TreeNode;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> diary;
        fun(root, 0, targetSum, diary, res);
        return res;
    }

    void fun(node* root, int sum, int targetSum, vector<int> &diary, vector<vector<int>> &res) {
        if (root == nullptr) return;

        sum += root->val;
        diary.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                res.push_back(diary);  // store full path
            }
            diary.pop_back(); // backtrack
            return;
        }

        fun(root->left, sum, targetSum, diary, res);
        fun(root->right, sum, targetSum, diary, res);

        diary.pop_back(); // backtrack after exploring children
    }
};
