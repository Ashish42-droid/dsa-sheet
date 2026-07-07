class Solution {
public:
    long long sumAndMultiply(int n) {
    long long digitsum = 0;
    long long sum=0;
    long long placevalue =1;
    while(n>0){
        long long rem = n % 10;
        if (rem!=0){
            sum +=(rem*placevalue);
            digitsum+=rem;
            placevalue*=10;
        }
        n/=10;
    }
    return sum*digitsum;
    }
};