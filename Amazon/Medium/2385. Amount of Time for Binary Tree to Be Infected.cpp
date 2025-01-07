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
    void dfs(TreeNode* root, map<int, set<int>>& adj) {
        // transition
        if(root->left) {
            adj[root->val].insert(root->left->val);
            adj[root->left->val].insert(root->val);
            dfs(root->left, adj);
        }
        if(root->right) {
            adj[root->val].insert(root->right->val);
            adj[root->right->val].insert(root->val);
            dfs(root->right, adj);
        }
    }

    int f(map<int, set<int>>& adj, int start) {
        int minTime = 0;
        queue<pair<int, int>> q;
        q.push({minTime, start});
        map<int, bool> vis;
        vis[start] = true;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int time = it.first;
            int node = it.second;
            minTime = std::max(minTime, time);
            for(auto& child: adj[node]) {
                if(!vis[child]) {
                    vis[child] = true;
                    q.push({time+1, child});
                }
            } 
        }
        return minTime;
    }

    int amountOfTime(TreeNode* root, int start) {
        map<int, set<int>> adj;
        dfs(root, adj);
        return f(adj, start);
        return 0;
    }
};