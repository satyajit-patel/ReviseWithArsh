class Solution {
public:
    map<vector<int>, int> dp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(dp[needs]) {
            return dp[needs];
        }

        int n = price.size();
        int m = special.size();

        int minCost = 0;
        for(int i=0; i<n; i++) {
            minCost += (needs[i] * price[i]);
        }

        for(int i=0; i<m; i++) {
            bool isGoodOffer = true;
            for(int j=0; j<n; j++) {
                if(special[i][j] > needs[j]) {
                    isGoodOffer = false;
                    break;
                }
            }
            if(isGoodOffer) {
                // apply offer
                for(int j=0; j<n; j++) {
                    needs[j] -= special[i][j];
                }
                int newCost = special[i].back() + shoppingOffers(price, special, needs);
                // we have to check again as there might some nneds left
                minCost = std::min(minCost, newCost);
                // backtrack
                for(int j=0; j<n; j++) {
                    needs[j] += special[i][j];
                }
            }
        }
        return dp[needs] = minCost;
    }
};