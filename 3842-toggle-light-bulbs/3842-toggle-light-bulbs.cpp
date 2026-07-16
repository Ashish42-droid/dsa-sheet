class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
      unordered_map<int,int> mp ;
      for (int b : bulbs){
        mp[b]++;

      }
      vector<int> result;
      for(auto &count : mp ){
        if (count.second %2==1)
        result.push_back(count.first);

      }

      sort(result.begin(),result.end());
      return result;
    }
};