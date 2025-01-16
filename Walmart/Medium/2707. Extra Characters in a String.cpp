class Solution {
public:
    int dp[50+1];
    int f(int i, string& s, unordered_set<string>& st) {
        // base case
        if(i >= s.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        int take = 1e9;
        for(int j=i; j<s.size(); j++) {
            if(st.find(s.substr(i, j-i+1)) != st.end()) {
                take = min(take, f(j+1, s, st));
            }
        }
        int notTake = 1 + f(i+1, s, st);

        // ans
        int ans = min(take, notTake);
        dp[i] = ans;
        return ans;
    }

    int minExtraChar(string& s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        memset(dp, -1, sizeof dp);
        int ans = f(0, s, st);
        return ans;
    }
};