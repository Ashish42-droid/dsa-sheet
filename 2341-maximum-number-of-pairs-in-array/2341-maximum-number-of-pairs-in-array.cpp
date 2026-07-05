class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> f;
        for (int n : nums)
        f[n]++;
        int pairs=0;
        int left=0;
        for (auto it: f){
        pairs+=it.second/2;
        left+=it.second%2;
        }
        return {pairs,left};
         }
};