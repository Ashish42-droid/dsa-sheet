class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum =0;
        vector<int> diary;
        vector<vector<int>>res;
        int idx=0;
        fun (candidates,n,0,sum,diary,res,target);
         return res;
    }

    void fun (vector<int>& candidates,int n,int idx,int sum ,vector<int>&diary,vector<vector<int>>&res, int target){
       if (idx==n){
        if (sum == target)
        res.push_back(diary);
        return;
       }
// nahi lena hai 
fun (candidates,n,idx+1,sum,diary,res,target);

//lena hai
if (candidates[idx]+sum<=target){
    diary.push_back(candidates[idx]);
    sum+=candidates[idx];
    fun (candidates,n,idx,sum,diary,res,target);
    diary.pop_back();
    sum-=candidates[idx];

}
return;
    }
};