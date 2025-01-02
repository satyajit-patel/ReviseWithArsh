class Solution {
public:
    int state(int i, int prev, vector<vector<int>>& e, vector<vector<int>>& dp) {
        // base case
        if(i >= e.size()) {
            return 0;
        }
        if(dp[i][prev+1] != -1) {
            return dp[i][prev+1];
        }

        // transition
        int take = 0;
        if(prev == -1 || (e[prev][0] < e[i][0] && e[prev][1] < e[i][1])) {
            take = 1 + state(i+1, i, e, dp);
        }
        int notTake = state(i+1, prev, e, dp);

        // ans
        int ans = max(take, notTake);
        dp[i][prev+1] = ans;
        return ans;
    }

    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size();

        // sort(e.begin(), e.end());
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = state(0, -1, e, dp);
        // return ans;

            // or
        sort(e.begin(), e.end(), comp);
        vector<int> heights;
        for(auto& it: e) {
            heights.push_back(it[1]);
        }
        set<int> lis;
        for(auto& it: heights) {
            auto lb = lis.lower_bound(it);
            if(lb == lis.end()) {
                lis.insert(it);
            } else {
                lis.erase(lb);
                lis.insert(it);
            }
        }
        return lis.size();
    }
};