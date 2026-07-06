class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for (int i =0;i<score.size();i++){
            pq.push({score[i],i});}
            vector <string> res(score.size());
           int rank = 1;
            while(!pq.empty()){
               auto  top = pq.top();
                pq.pop();
            if (rank == 1) res[top.second] = "Gold Medal";
            else if (rank == 2) res[top.second] = "Silver Medal";
            else if (rank == 3) res[top.second] = "Bronze Medal";
            else res[top.second] = to_string(rank);

            rank++;
            }
        return res;   
    }
};