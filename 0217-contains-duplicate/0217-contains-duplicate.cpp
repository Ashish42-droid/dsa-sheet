class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_map<int,int> mp;
        for (int n:nums){
            mp[n]++;
        }
        priority_queue<pair<int,int>> pq;
        for (auto it : mp){
             pq.push({it.second,it.first});
        }
        auto  top = pq.top().first;
        if (top >=2)
        return true;
        else return false  ;
    }
};
       