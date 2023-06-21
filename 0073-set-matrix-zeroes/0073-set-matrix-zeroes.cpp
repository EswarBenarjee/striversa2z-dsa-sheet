class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rows, columns;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }

        for(auto i: rows) {
            for(int j=0; j<n; j++) {
                matrix[i][j] = 0;
            }
        } 

        for(auto i: columns) {
            for(int j=0; j<m; j++) {
                matrix[j][i] = 0;
            }
        }
    }
};