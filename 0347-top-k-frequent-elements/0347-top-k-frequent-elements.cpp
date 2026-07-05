class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         struct cmp{
        bool operator()(pair<int,int> &nums, pair<int,int> &b){
            return nums.first > b.first;
        }
    };
      unordered_map <int,int>f;
      for (int i=0;i<nums.size();i++){
        f[nums[i]]++;

      }
      priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
      pair<int,int> curr;
      for (auto it:f){
        curr = {it.second,it.first};
        if (pq.size()<k)
           pq.push(curr);
        else{
     if(curr.first < pq.top().first)
            continue;
            else{
                pq.pop();
                pq.push(curr);
            }
        }

      }
      vector <int> res;
      while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();

      }
      return res;
    }
};