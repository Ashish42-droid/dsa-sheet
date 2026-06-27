class Solution {
public:
    bool possible (vector<int>&piles,int h ,long long guess){
        int hours =0;
      for (int banana:piles){
        int q = banana / guess;
        int r = banana  % guess;
        hours+=q;
        if (r!=0)
        hours++;
        if (hours>h)
        return false;
        
      }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    long long n= piles.size();
    long long low=1;
     long long high = *max_element(piles.begin(),piles.end());
    

    while(low<=high){
        long long guess=( low+high)/2;
         if (possible(piles,h,guess))
          high = guess -1;
         else 
        low =guess+1;

    }
    return low;
    }
};