/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1, maxSum = INT_MIN, currentLevel = 1;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int s = q.size();
            int sum = 0;
            for(int k=0; k<s; k++) {
                TreeNode *temp = q.front();
                q.pop();
                sum += temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(sum > maxSum) {
                ans = currentLevel;
                maxSum = sum;
            }
            currentLevel++;
        }
        return ans;
    }
};