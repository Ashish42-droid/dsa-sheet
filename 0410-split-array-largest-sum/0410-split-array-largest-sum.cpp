class Solution {
public:
    bool fun(vector<int>&nums,int k, int limit){
        int p=1;
        int sum=0;
        for (int i=0;i<nums.size();i++){
            if (sum+nums[i]<=limit)
            {
                sum+=nums[i];
            }
            else{
                p++;
                sum=nums[i];
                if(p>k) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        if (k>nums.size()) return -1;
        int res=-1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int limit=(low+high)/2;
            if (fun(nums,k,limit)){
                res=limit;
                high=limit-1;
            }
            else
            low=limit+1;
        }
        return res;
    }
};