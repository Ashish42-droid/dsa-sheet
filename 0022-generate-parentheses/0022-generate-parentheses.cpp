class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
       fun(0,0,n,temp,res);
         return res;

    }

    void  fun(int open,int close,int n,string &temp,vector<string>&res){
    if (open==n && close==n){
        res.push_back(temp);
        return ;
    }
    if (open<n){
        temp.push_back('(');
        fun (open+1,close,n,temp,res);
        temp.pop_back();

    }
    if (close<open){
        temp.push_back(')');
        fun (open,close+1,n,temp,res);
        temp.pop_back();
    }
}
};
/*fun(open=0, close=0, temp="")
  open(0) < n(2) → TRUE  → push '(' → temp = "("
  
    fun(open=1, close=0, temp="(")
      open(1) < n(2) → TRUE → push '(' → temp = "(("
      
        fun(open=2, close=0, temp="((")
          open(2) < n(2) → FALSE → skip
          close(0) < open(2) → TRUE → push ')' → temp = "(()"
          
            fun(open=2, close=1, temp="(()")
              open(2) < n(2) → FALSE → skip
              close(1) < open(2) → TRUE → push ')' → temp = "(())"
              
                fun(open=2, close=2, temp="(())")
                  open==n && close==n → TRUE
                  ✅ res.push_back("(())")
                  return
                  
              pop_back() → temp back to "(()"
            return (from fun(2,1))
          pop_back() → temp back to "(("
        return (from fun(2,0))
      pop_back() → temp back to "("
      
      close(0) < open(1) → TRUE → push ')' → temp = "()"
      
        fun(open=1, close=1, temp="()")
          open(1) < n(2) → TRUE → push '(' → temp = "()("
          
            fun(open=2, close=1, temp="()(")
              open(2) < n(2) → FALSE → skip
              close(1) < open(2) → TRUE → push ')' → temp = "()()"
              
                fun(open=2, close=2, temp="()()")
                  open==n && close==n → TRUE
                  ✅ res.push_back("()()")
                  return
                  
              pop_back() → temp back to "()("
            return (from fun(2,1) second visit)
          pop_back() → temp back to "()"
          
          close(1) < open(1) → FALSE → skip (no more branches here)
        return (from fun(1,1))
      pop_back() → temp back to ""
    return (from fun(1,0))
  pop_back() → temp back to ""
return (from fun(0,0)) → DONE

Final res = ["(())", "()()"]



fun(0,0,"")
                                   |
                                (L) push '('
                                   |
                              fun(1,0,"(")
                              /              \
                    (L) push '('          (R) push ')'
                        /                        \
                 fun(2,0,"((")              fun(1,1,"()")
                       |                          |
                (R) push ')'                (L) push '('
                       |                          |
                fun(2,1,"(()")             fun(2,1,"()(")
                       |                          |
                (R) push ')'                (R) push ')'
                       |                          |
                fun(2,2,"(())")           fun(2,2,"()()")
                   ✅ SAVE                    ✅ SAVE
              "(())" added to res        "()()" added to res*/
