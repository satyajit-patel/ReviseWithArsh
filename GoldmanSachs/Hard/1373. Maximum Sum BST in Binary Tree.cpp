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
    int ans;

    vector<int> f(TreeNode* root) {
        // base case
        if(!root) {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            int sum = 0;
            return {mini, maxi, sum};
        }

        // transition
        vector<int> l = f(root->left);
        vector<int> r = f(root->right);

        // ans
        int leftMin = l[0];
        int leftMax = l[1];
        int rightMin = r[0];
        int rightMax = r[1];
        int x = root->val;
        if((leftMax < x) && (x < rightMin)) {
            int mini = min(x, leftMin);
            int maxi = max(x, rightMax);
            int sum = x + l[2] + r[2];
            ans = max(ans, sum);
            return {mini, maxi, sum};
        }
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int sum = max(l[2], r[2]);
        return {mini, maxi, sum};
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        vector<int> info = f(root); // {minVal, maxVal, sum}
        return ans;
    }
};