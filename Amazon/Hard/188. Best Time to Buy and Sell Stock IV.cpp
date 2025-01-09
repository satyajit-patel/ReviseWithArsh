class Solution {
public:
    vector<int> a;
    unordered_map<string, int> dp;

    int state(int i, int canBuy, int transaction) {
        // base case
        if(i >= a.size()) {
            return 0;
        }
        if(transaction == 0) {
            return 0;
        }
        string key = to_string(i) + "_" + to_string(canBuy) + "_" + to_string(transaction);
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }

        // transition
        int maxi = INT_MIN;
        if(canBuy) {
            int buy = -a[i] + state(i+1, 0, transaction); // we can buy again only after selling
            int notBuy = state(i+1, 1, transaction);
            maxi = max(buy, notBuy);
        } else {
            int sell = a[i] + state(i+1, 1, transaction-1);
            int notSell = state(i+1, 0, transaction);
            maxi = max(sell, notSell);
        }
        
        // ans
        dp[key] = maxi;
        return maxi;
    }

    int maxProfit(int k, vector<int>& prices) {
        a.clear();
        a = prices;
        dp.clear();
        int maxProfit = state(0, 1, k);
        return maxProfit;
    }
};