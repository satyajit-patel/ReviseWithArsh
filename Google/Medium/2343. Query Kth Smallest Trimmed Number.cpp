class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        map<int, vector<pair<string, int>>> mp;
        int n = nums.size();
        int m = nums[0].size();
        
        // Precompute trimmed numbers for all possible lengths
        for (int key = 1; key <= m; key++) {
            vector<pair<string, int>> temp;
            for (int i = 0; i < n; i++) {
                string s = nums[i];
                string str = s.substr(m - key); // Trim the last 'key' characters
                temp.push_back({str, i});
            }
            sort(temp.begin(), temp.end()); // Lexicographical sorting of strings
            mp[key] = temp;
        }
        
        vector<int> ans;
        for (auto& it : queries) {
            int kth = it[0];
            int key = it[1];
            vector<pair<string, int>> temp = mp[key];
            ans.push_back(temp[kth - 1].second); // Get the index of the kth smallest trimmed number
        }
        
        return ans;
    }
};
