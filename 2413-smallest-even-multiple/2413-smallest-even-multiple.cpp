class Solution {
public:
    int smallestEvenMultiple(int n) {
        int op= n*2;
        if (n%2==0){
            int ans = op/2;
            return ans;
        }
        else return op;
    }
};