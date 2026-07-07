class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
    int n=profit.size();
    vector<pair<int,int>> proj;
    int i;
    for(i=0;i<n;i++){
        proj.push_back({capital[i],profit[i]});
    }
    sort(proj.begin(),proj.end());
    priority_queue<int> pq;
    int idx=0;
    while(k--){
        while(idx<n){
            if(proj[idx].first>w){
                break;
            }
            pq.push(proj[idx].second);
            idx++;
        }
        if(pq.empty()){
            return w;
        }
        w=w+pq.top();
        pq.pop();

    }
    return w;    
    }
};