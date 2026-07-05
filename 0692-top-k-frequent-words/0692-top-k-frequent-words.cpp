class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
    
      struct cmp {
    bool operator()(const pair<int,string> &a, const pair<int,string> &b) const {
        if (a.first == b.first)
            return a.second < b.second; // ✅ reverse lexicographic
        return a.first > b.first;       // smaller frequency first
    }
};

      unordered_map <string,int>f;
      for (int i=0;i<words.size();i++){
        f[words[i]]++;

      }
      priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
    
      
        for (auto it : f) {
            pq.push({it.second, it.first});
            if (pq.size() > k) pq.pop();
        }
      vector <string> res;
      while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();

      }
      reverse(res.begin(),res.end());
      return res;
    }

};