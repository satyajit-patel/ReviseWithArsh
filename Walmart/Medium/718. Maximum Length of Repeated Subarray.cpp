class Solution {
public:
    int maxi;
    int dp[1000+1][1000+1];

    int f(int i, int j, vector<int>& a, vector<int>& b) {
        // base case
        if(i >= a.size()) {
            return 0;
        }
        if(j >= b.size()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // transition
        int len = 0;
        if(a[i] == b[j]) {
            len = 1 + f(i+1, j+1, a, b);
            maxi = max(maxi, len);
        }
        f(i+1, j, a, b);
        f(i, j+1, a, b);
        dp[i][j] = len;
        return len;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        maxi = 0;
        memset(dp, -1, sizeof dp);
        f(0, 0, nums1, nums2);
        return maxi;
    }
};