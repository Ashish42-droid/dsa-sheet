class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        fun(nums, n, 0, res);
        return res;
    }

    void fun(vector<int>& nums, int n, int idx, vector<vector<int>>& res) {
        if (idx == n) {
            res.push_back(nums);   // nums itself is now one full permutation
            return;
        }
        for (int j = idx; j < n; j++) {
            swap(nums[idx], nums[j]);      // place nums[j] at position idx
            fun(nums, n, idx + 1, res);     // recurse on next position
            swap(nums[idx], nums[j]);      // undo swap (backtrack)
        }
    }
};