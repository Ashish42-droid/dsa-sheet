class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low =0;
        int high =nums.size()-1;
        int res=nums.size();
        while (low<=high){
          int  guess=(low + high)/2;
            if (nums[guess]<target)
            low=guess+1;
            else{
                res=guess;
                high=guess-1;
            }
            
        }
        return res;
    }
};