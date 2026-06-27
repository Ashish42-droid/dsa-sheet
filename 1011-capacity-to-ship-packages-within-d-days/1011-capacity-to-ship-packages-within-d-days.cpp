class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int res=1;
       int  low=*max_element(weights.begin(),weights.end());
       int  high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int guess= (low+high)/2;
            int requireddays=1;
            int currentload=0;
            for (int w : weights){
               
                if (currentload+w>guess)
                {requireddays++;
                currentload=0;}
                 currentload+=w;

            }
            if (requireddays>days)
            low= guess+1;
            else{
                res=guess;
                high=guess-1;

            }

            

        }
        return res;
        
    }
};