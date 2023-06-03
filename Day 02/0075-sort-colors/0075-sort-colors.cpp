class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(3, 0);
        for(auto i: nums) count[i]++;

        int j = 0;
        for(int i=0; i<n; i++) {
            if(count[j]>0) {
                nums[i] = j;
                count[j]--;
            } else {
                while(count[j] == 0) j++;
                nums[i] = j;
                count[j]--;
            }
        }
    }
};