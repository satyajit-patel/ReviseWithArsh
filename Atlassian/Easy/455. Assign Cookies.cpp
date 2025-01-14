class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int i = 0, j = 0;
        int m = s.size();
        int n = g.size();
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        while((j < m) && (i < n)) {
            if(s[j] >= g[i]) {
                // satisfies the ego
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};