class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
       int n = matrix.size();
   
       for (int r=0;r<n;r++){
          unordered_set<int> rows , cols ;
        for (int c=0;c<n;c++){
      
           int rowval =matrix[r][c];
           int colval =matrix[c][r];
           if(rowval<1||rowval>n||colval<1||colval>n)
           return false;
           if (rows.count(rowval)||cols.count(colval))
           return false;
           rows.insert(rowval);
           cols.insert(colval);

        }
       }
       return true;
    }
};