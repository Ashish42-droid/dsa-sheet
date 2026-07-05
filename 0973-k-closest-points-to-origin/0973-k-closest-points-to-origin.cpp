class Solution {
public:
int distance(vector<int>&points){
    int x = points[0];
    int y = points[1];
    return (x*x+y*y);
}
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     priority_queue<pair<int,int>> pq;
     for(int i=0;i<points.size();i++){
        int dis = distance(points[i]);
        pq.push({dis,i});
        if (pq.size()>k)
        pq.pop();

     }
     vector<vector<int>>res;
     while(!pq.empty()){
        int idx = pq.top().second;
        res.push_back(points[idx]);
        pq.pop();

     }
     return res;
     
       }
};