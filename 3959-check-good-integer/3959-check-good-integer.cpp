class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitsum = 0;
        int squaresum = 0;

        while (n > 0) {   
            int rem = n % 10;
            digitsum += rem;
            squaresum += (rem * rem);
            n /= 10;
        }

        int diff =  squaresum - digitsum ;
        return diff >= 50;   // or abs(diff) <= 50 if needed
    }
};
