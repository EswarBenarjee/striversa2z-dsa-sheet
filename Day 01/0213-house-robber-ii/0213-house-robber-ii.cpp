class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return -1;
        if(n == 1) return nums[0];
         
        vector<int> dp1(n, -1), dp2(n, -1);

        return max(helper(nums, dp1, 0, n-1), helper(nums, dp2, 1, n));
    }
private:
    int helper(vector<int>& nums, vector<int>& dp, int index, int n) {
        if(index >= n) return 0;

        if(dp[index] != -1) return dp[index];

        dp[index] = max(nums[index]+helper(nums, dp, index+2, n), helper(nums, dp, index+1, n));
        return dp[index];
    }
};