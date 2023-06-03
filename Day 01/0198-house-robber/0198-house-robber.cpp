class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return helper(nums, dp, 0, n);
    }
private:
    int helper(vector<int>& nums, vector<int>& dp, int index, int n) {
        if(index >= n) return 0;

        if(dp[index] != -1) return dp[index];

        dp[index] = max(nums[index] + helper(nums, dp, index+2, n), helper(nums, dp, index+1, n));
        return dp[index];
    }
};