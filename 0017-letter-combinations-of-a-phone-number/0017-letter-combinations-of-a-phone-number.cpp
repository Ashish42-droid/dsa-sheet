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

/*fun(idx=0, diary="")
  idx(0) != n(2) → don't save
  choice = f[digits[0]] = f['2'] = "abc"
  
  loop j=0 → choice[0]='a'
    diary.push_back('a') → diary="a"
    
    fun(idx=1, diary="a")
      idx(1) != n(2) → don't save
      choice = f[digits[1]] = f['3'] = "def"
      
      loop j=0 → choice[0]='d'
        diary.push_back('d') → diary="ad"
        
        fun(idx=2, diary="ad")
          idx(2) == n(2) → ✅ SAVE "ad"
          return
          
        diary.pop_back() → diary="a"
      
      loop j=1 → choice[1]='e'
        diary.push_back('e') → diary="ae"
        
        fun(idx=2, diary="ae")
          idx(2) == n(2) → ✅ SAVE "ae"
          return
          
        diary.pop_back() → diary="a"
      
      loop j=2 → choice[2]='f'
        diary.push_back('f') → diary="af"
        
        fun(idx=2, diary="af")
          idx(2) == n(2) → ✅ SAVE "af"
          return
          
        diary.pop_back() → diary="a"
      
      loop ends (j=3 == choice.size()=3)
      return (from fun(idx=1,"a"))
      
    diary.pop_back() → diary="" (back at idx=0 level, undo 'a')
  
  loop j=1 → choice[1]='b'
    diary.push_back('b') → diary="b"
    
    fun(idx=1, diary="b")
      choice = "def"
      
      loop j=0 → 'd'
        diary="bd"
        fun(idx=2,"bd") → ✅ SAVE "bd"
        pop → diary="b"
      
      loop j=1 → 'e'
        diary="be"


fun(0,"")
├── 'a' → fun(1,"a")
│         ├── 'd' → fun(2,"ad") ✅ SAVE "ad"
│         ├── 'e' → fun(2,"ae") ✅ SAVE "ae"
│         └── 'f' → fun(2,"af") ✅ SAVE "af"
│
├── 'b' → fun(1,"b")
│         ├── 'd' → fun(2,"bd") ✅ SAVE "bd"
│         ├── 'e' → fun(2,"be") ✅ SAVE "be"
│         └── 'f' → fun(2,"bf") ✅ SAVE "bf"
│
└── 'c' → fun(1,"c")
          ├── 'd' → fun(2,"cd") ✅ SAVE "cd"
          ├── 'e' → fun(2,"ce") ✅ SAVE "ce"
          └── 'f' → fun(2,"cf") ✅ SAVE "cf"


fun(idx=0, diary="")
                                digits[0]='2' → choice="abc"
                    ┌───────────────────┼───────────────────┐
                  push'a'             push'b'             push'c'
                    │                   │                   │
            fun(idx=1,"a")      fun(idx=1,"b")      fun(idx=1,"c")
          digits[1]='3'→"def"  digits[1]='3'→"def"  digits[1]='3'→"def"
              ┌───┼───┐            ┌───┼───┐            ┌───┼───┐
            'd' 'e' 'f'          'd' 'e' 'f'          'd' 'e' 'f'
             │   │   │            │   │   │            │   │   │
            "ad""ae""af"        "bd""be""bf"        "cd""ce""cf"
             ✅  ✅  ✅           ✅  ✅  ✅           ✅  ✅  ✅

*/
