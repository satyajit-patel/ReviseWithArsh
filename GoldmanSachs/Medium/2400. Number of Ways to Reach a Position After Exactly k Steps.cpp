class Solution {
public:
    int dp[4000+1][1000+1];
    int mod = 1e9 + 7;

    int f(int startPos, int endPos, int k) {
        // base case
        if(k == 0) {
            return startPos == endPos;
        }
        if(dp[startPos+1000][k] != -1) {
            return dp[startPos+1000][k];
        }

        // transition
        int option1 = f(startPos-1, endPos, k-1);
        int option2 = f(startPos+1, endPos, k-1);

        // ans
        int ans = (option1 + option2) % mod;
        dp[startPos+1000][k] = ans;
        return ans;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof dp);
        return f(startPos, endPos, k);
    }
};