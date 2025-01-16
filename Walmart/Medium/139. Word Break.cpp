class Solution {
public:
    int dp[300+1];

    bool f(int i, string& s, unordered_set<string>& us) {
        // bade case
        if(i >= s.size()) {
            return true;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        // trnasition
        for(int j=i; j<s.size(); j++) {
            string temp = s.substr(i, j-i+1);
            if(us.find(temp) != us.end()) {
                if(f(j+1, s, us)) {
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string& s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        memset(dp, -1, sizeof dp);
        return f(0, s, us);
    }
};