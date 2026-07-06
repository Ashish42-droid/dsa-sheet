class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int n:nums){
            mp[n]++;
        }
        priority_queue<pair<int,int>> pq;
        for (auto it : mp){
             pq.push({it.second,it.first});
        }
        auto  top = pq.top().second;
        return top;
    }
};