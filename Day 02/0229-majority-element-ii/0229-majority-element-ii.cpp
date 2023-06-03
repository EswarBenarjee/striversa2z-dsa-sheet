class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        set<int> s;
        
        for(auto i: nums) {
            m[i]++;
            if(m[i] > n/3) s.insert(i);
        }
        
        return vector<int>(s.begin(), s.end());
    }
};