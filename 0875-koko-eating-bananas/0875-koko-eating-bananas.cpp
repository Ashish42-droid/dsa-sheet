class Solution {
public:
    long long possible(vector<int>& piles, long long guess) {
        long long hours = 0;
        for (int banana : piles) {
            long long q = banana / guess;
            long long r = banana % guess;
            hours += q;
            if (r != 0) hours++;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        int res = -1;

        while (low <= high) {
            long long guess = (low + high) / 2;
            long long hours = possible(piles, guess);

            if (hours > h) {
                // too slow, increase speed
                low = guess + 1;
            } else {
                // valid speed, try slower
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};
