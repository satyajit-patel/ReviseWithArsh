class Solution {
public:
    int equalSubstring(string& s, string& t, int maxCost) {
        int n = s.size();
        int maxi = 0;
        for(int i=0,init=0; i<n; i++) {
            maxCost -= abs(s[i] - t[i]);
            while(maxCost < 0) {
                maxCost += abs(s[init] - t[init++]);
            }
            maxi = max(maxi, i-init+1);
        }
        return maxi;
    }
};