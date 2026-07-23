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
/*Initial Call:  
hasPathSum(root=5, targetSum=22)

check=false, sum=0

Calls fun(5, 22, 0, check)

Call 1: fun(5, 22, sum=0)

sum = 0+5 = 5

Not leaf → recurse left → fun(4, 22, 5)

Call 2: fun(4, 22, sum=5)

sum = 5+4 = 9

Not leaf → recurse left → fun(11, 22, 9)

Call 3: fun(11, 22, sum=9)

sum = 9+11 = 20

Not leaf → recurse left → fun(7, 22, 20)

Call 4: fun(7, 22, sum=20)

sum = 20+7 = 27

Leaf → check 27==22 → ❌ false

Backtrack to node 11 (left subtree finished).

Call 5: fun(2, 22, sum=20)

sum = 20+2 = 22

Leaf → check 22==22 → ✅ true

check=true → return immediately.

Backtrack to node 11 (right subtree finished, success found).*/