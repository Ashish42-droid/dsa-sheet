class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int r = 0; r < n; r++) {
            vector<bool> rowSeen(n+1, false);
            vector<bool> colSeen(n+1, false);

            for (int c = 0; c < n; c++) {
                int rowVal = matrix[r][c];
                int colVal = matrix[c][r];

                if (rowVal < 1 || rowVal > n || colVal < 1 || colVal > n)
                    return false;

                if (rowSeen[rowVal] || colSeen[colVal])
                    return false;

                rowSeen[rowVal] = true;
                colSeen[colVal] = true;
            }
        }
        return true;
    }
};
