// https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> pathGrid;
    char ch;
    string ans;

    int getMCM(vector<int>& a, int i, int j) {
        // base case
        if(i == j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // transition
        int mini = INT_MAX;
        for(int k=i; k<j; k++) {
            int l = getMCM(a, i, k);
            int r = getMCM(a, k+1, j);
            int c = a[i-1] * a[j] * a[k];
            int cost = l + r + c;
            if(cost < mini) {
                mini = cost;
                pathGrid[i][j] = k;  // Store the index of the optimal split
            }
        }
        
        // ans
        dp[i][j] = mini;
        return mini;
    }
    
    void dfs(int i, int j) {
        // base case
        if(i == j) {
            ans += ch++;
            return;
        }
        
        // transition
        ans += '(';
        dfs(i, pathGrid[i][j]);
        dfs(pathGrid[i][j]+1, j);
        ans += ')';
    }

    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        dp.clear();
        dp.resize(n+1, vector<int>(n+1, -1));
        pathGrid.clear();
        pathGrid.resize(n+1, vector<int>(n+1, -1));
        int mcm = getMCM(arr, 1, n-1);
        ch = 'A';
        ans.clear();
        dfs(1, n-1);
        return ans;
    }
};
