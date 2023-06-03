class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<vector<int>> ans;

        ans.push_back(vector<int>{1});
        if(rowIndex == 1) return ans[0];

        for(int i=2; i<rowIndex+1; i++) {
            vector<int> temp;
            temp.push_back(1); 
            for(int j=1; j<i-1; j++) {
                temp.push_back( ans[i-2][j-1] + ans[i-2][j] );
            }
            temp.push_back(1); 
            ans.push_back(temp);
        }
        return ans[rowIndex-1];
    }
};