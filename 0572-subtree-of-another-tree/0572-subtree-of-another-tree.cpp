class Solution {
    using node = TreeNode;
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
       
        return isSame(root, subRoot) ||
               isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

    bool isSame(node* a, node* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        if (a->val != b->val) return false;
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
};