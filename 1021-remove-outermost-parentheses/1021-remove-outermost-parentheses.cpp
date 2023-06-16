class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;
        for(auto i: s) {
            if(i == '(') {
                if(st.size() > 0) ans += i;
                st.push(i);
            } else {
                st.pop();
                if(st.size() > 0) ans += i;
            }
        }
        return ans;
    }
};