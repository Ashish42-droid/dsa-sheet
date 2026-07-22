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
/*Initial state
q = [3]
res = []
ltr = 1 (true) → level 0 will fill LEFT to RIGHT

OUTER LOOP — Iteration 1 (Level 0)
q.empty()? NO
lvl = q.size() = 1
first = 0, last = lvl-1 = 0
temp = [_]  (size 1)
ltr = 1 → fill LEFT to RIGHT (using `first`)
INNER LOOP (runs 1 time):
Inner 1: (lvl=1→0)
  t = q.front() = node(3)
  q.pop()                          → q = []
  ltr==1 → temp[first]=3 → temp[0]=3, first++ → first=1
  temp = [3]
  
  t->left=node(9)  → q.push(9)     → q=[9]
  t->right=node(20)→ q.push(20)    → q=[9,20]
Inner loop ends
res.push_back(temp)   → res = [[3]]
ltr = 1 - ltr = 1 - 1 = 0 → ltr = false
State after Level 0: q=[9,20], res=[[3]], ltr=false

OUTER LOOP — Iteration 2 (Level 1)
q.empty()? NO
lvl = q.size() = 2
first = 0, last = lvl-1 = 1
temp = [_, _]
ltr = 0 → fill RIGHT to LEFT (using `last`, since ltr==1 check fails)
INNER LOOP (runs 2 times):
Inner 1: (lvl=2→1)
  t = q.front() = node(9)
  q.pop()                          → q=[20]
  ltr==1? NO (ltr=0) → else branch → temp[last]=9 → temp[1]=9, last-- → last=0
  temp = [_, 9]
  
  t->left=null → skip
  t->right=null → skip

Inner 2: (lvl=1→0)
  t = q.front() = node(20)
  q.pop()                          → q=[]
  ltr==1? NO → else → temp[last]=20 → temp[0]=20, last-- → last=-1
  temp = [20, 9]
  
  t->left=node(15) → q.push(15)    → q=[15]
  t->right=node(7) → q.push(7)     → q=[15,7]
Inner loop ends
res.push_back(temp)   → res = [[3], [20,9]]
ltr = 1 - ltr = 1 - 0 = 1 → ltr = true
State after Level 1: q=[15,7], res=[[3],[20,9]], ltr=true

OUTER LOOP — Iteration 3 (Level 2)
q.empty()? NO
lvl = q.size() = 2
first = 0, last = lvl-1 = 1
temp = [_, _]
ltr = 1 → fill LEFT to RIGHT
INNER LOOP (runs 2 times):
Inner 1: (lvl=2→1)
  t = q.front() = node(15)
  q.pop()                          → q=[7]
  ltr==1 → temp[first]=15 → temp[0]=15, first++ → first=1
  temp = [15, _]
  
  t->left=null, t->right=null → nothing pushed

Inner 2: (lvl=1→0)
  t = q.front() = node(7)
  q.pop()                          → q=[]
  ltr==1 → temp[first]=7 → temp[1]=7, first++ → first=2
  temp = [15, 7]
  
  t->left=null, t->right=null → nothing pushed
Inner loop ends
res.push_back(temp)   → res = [[3], [20,9], [15,7]]
ltr = 1 - ltr = 1 - 1 = 0 → ltr = false (irrelevant, loop ends next)
State after Level 2: q=[], res=[[3],[20,9],[15,7]]

OUTER LOOP — Iteration 4
q.empty()? YES → outer while loop terminates

Final Result
cppres = [[3], [20, 9], [15, 7]]
*/