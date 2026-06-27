class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    long long n= piles.size();
    long long low=1;
     long long high = *max_element(piles.begin(),piles.end());
    

    while(low<=high){
        long long guess=( low+high)/2;
         long long hours=0;
        for( int banana:piles){
           hours+=ceil((double)banana/guess);
        }
       
         if (hours<=h)//speed bahut jyada hai  slow speed try karo
        high =guess-1;
        else 
        low=guess+1;
    }    
    return low;
    }
};