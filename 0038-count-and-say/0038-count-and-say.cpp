class Solution {
public:
    string countAndSay(int n) {
        int count, number;
        string ans = "1";
        while(--n) {
            count = 1;
            string newStr = "";
            for(int i=1; i<ans.size(); i++) {
                if(ans[i] == ans[i-1]) {
                    count++;
                } else {
                    newStr += to_string(count) + ans[i-1];
                    count = 1;
                }
            }
            newStr += to_string(count) + ans[ans.size()-1];
            ans = newStr;
        }
        return ans;
    }
};