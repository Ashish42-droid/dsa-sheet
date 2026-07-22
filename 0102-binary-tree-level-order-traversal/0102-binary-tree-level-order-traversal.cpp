class Solution {
    using Node = TreeNode;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelsize = q.size();
            vector<int> temp;

            while (levelsize--) {
                Node* t = q.front();
                q.pop();
                temp.push_back(t->val);

                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }

            res.push_back(temp);
        }
        return res;
    }
};

/*Step-by-Step Trace
Initial state
q = [3]
res = []

OUTER LOOP — Iteration 1 (Level 0)
q.empty()? NO → enter loop
levelsize = q.size() = 1        // only node "3" belongs to this level
temp = []
INNER LOOP (runs while levelsize-- is truthy, i.e., 1 time):
Inner iteration 1: (levelsize was 1, becomes 0 after this check, loop runs once)
  t = q.front() = node(3)
  q.pop()                        → q = []
  temp.push_back(3)              → temp = [3]
  
  t->left = node(9) ≠ null → q.push(9)   → q = [9]
  t->right = node(20) ≠ null → q.push(20) → q = [9, 20]
Inner loop check: levelsize is now 0 → while(0--) → 0 is falsy → inner loop ends
res.push_back(temp)   → res = [[3]]
State after Level 0: q = [9, 20], res = [[3]]

OUTER LOOP — Iteration 2 (Level 1)
q.empty()? NO → enter loop
levelsize = q.size() = 2        // nodes "9" and "20" belong to this level
temp = []
INNER LOOP (runs 2 times):
Inner iteration 1: (levelsize=2, check "2--" → truthy, levelsize becomes 1)
  t = q.front() = node(9)
  q.pop()                        → q = [20]
  temp.push_back(9)              → temp = [9]
  
  t->left = null → skip
  t->right = null → skip
  (node 9 has no children)

Inner iteration 2: (levelsize=1, check "1--" → truthy, levelsize becomes 0)
  t = q.front() = node(20)
  q.pop()                        → q = []
  temp.push_back(20)             → temp = [9, 20]
  
  t->left = node(15) ≠ null → q.push(15)  → q = [15]
  t->right = node(7) ≠ null → q.push(7)   → q = [15, 7]
Inner loop check: levelsize is now 0 → while(0--) falsy → inner loop ends
res.push_back(temp)   → res = [[3], [9,20]]
State after Level 1: q = [15, 7], res = [[3],[9,20]]

OUTER LOOP — Iteration 3 (Level 2)
q.empty()? NO → enter loop
levelsize = q.size() = 2        // nodes "15" and "7" belong to this level
temp = []
INNER LOOP (runs 2 times):
Inner iteration 1: (levelsize=2→1)
  t = q.front() = node(15)
  q.pop()                        → q = [7]
  temp.push_back(15)             → temp = [15]
  
  t->left = null → skip
  t->right = null → skip

Inner iteration 2: (levelsize=1→0)
  t = q.front() = node(7)
  q.pop()                        → q = []
  temp.push_back(7)              → temp = [15, 7]
  
  t->left = null → skip
  t->right = null → skip
Inner loop ends (levelsize reached 0)
res.push_back(temp)   → res = [[3],[9,20],[15,7]]
State after Level 2: q = [], res = [[3],[9,20],[15,7]]

OUTER LOOP — Iteration 4
q.empty()? YES → outer while loop terminates

Final Result
cppres = [[3], [9, 20], [15, 7]]
✅ Matches expected output.

Visual: Queue State Over Time
Time →   Before Lvl0   After Lvl0    After Lvl1    After Lvl2
Queue:      [3]          [9,20]        [15,7]          []
res:         []           [[3]]      [[3],[9,20]]  [[3],[9,20],[15,7]]
Diagram: which nodes get grouped into which level
Level 0:            3                    → temp=[3]      (levelsize was 1)
                   /   \
Level 1:          9    20                 → temp=[9,20]   (levelsize was 2)
                      /    \
Level 2:            15      7             → temp=[15,7]   (levelsize was 2)
*/