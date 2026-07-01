class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n =  a.size();
        int m =  a[0].size();
        int low=0;
        int high= (n*m)-1;
        while (low<=high){
            int guess=(low+high)/2;
            int row=guess/m;
            int col=guess%m;
            if(a[row][col]==target) return true;
            if (a[row][col]<target) low= guess+1;
            else high= guess-1;

        }
        return false;
    }
};