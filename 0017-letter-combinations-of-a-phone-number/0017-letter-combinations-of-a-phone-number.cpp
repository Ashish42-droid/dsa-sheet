class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> f = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        int n = digits.size();
        int idx=0;
        string diary;
        vector<string> res;
        fun (digits,n,idx,diary,f,res);
        
       
        return res;
    }

    void fun(string &digits,int n, int idx,string &diary,unordered_map<char,string>&f, vector<string>  &res){
        if (idx==n){
           res.push_back(diary);
           return ;
            }
            string choice = f [digits[idx]];
            for(int j=0;j<choice.size();j++){
                diary.push_back(choice[j]);
                 fun (digits,n,idx+1,diary,f,res);
                 diary.pop_back();

            }
               return ;
            }
};