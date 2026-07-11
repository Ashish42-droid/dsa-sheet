class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxrange = INT_MIN;
        vector<pair<int,int>> element;

        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            int maxdigit = INT_MIN;
            int mindigit = INT_MAX;

            

            while (temp > 0) {
                int digit = temp % 10;
                maxdigit = max(digit, maxdigit);
                mindigit = min(digit, mindigit);
                temp /= 10;
            }

            int range = maxdigit - mindigit;
            element.push_back({nums[i], range});
            maxrange = max(range, maxrange);
        }

        int sum = 0;
        for (auto &p : element) {
            if (p.second == maxrange)
                sum += p.first;
        }

        return sum;
    }
};
