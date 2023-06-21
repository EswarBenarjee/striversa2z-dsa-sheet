class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives, negatives, ans;
        for(auto i: nums) {
            i>0 ? positives.push_back(i) : negatives.push_back(i);
        }
        for(int i=0; i<positives.size(); i++) {
            ans.push_back(positives[i]);
            ans.push_back(negatives[i]);
        }
        return ans;
    }
};