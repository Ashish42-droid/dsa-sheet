class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map <char, int > freq;
        for (char s : text)
          { freq [s]++;}
        int b = freq['b'] / 1;
        int a = freq['a'] / 1;
        int l = freq['l'] / 2;
        int o = freq['o'] / 2;
        int n = freq['n'] / 1;
        return min({b,a,l,o,n});

        }
    
};