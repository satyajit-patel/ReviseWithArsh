class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> pairs(n);
        for(int i=0; i<n; i++) {
            pairs[i] = {nums[i], i};
        }
        sort(pairs.begin(), pairs.end());
        reverse(pairs.begin(), pairs.end());
        vector<pair<int, int>> topK(pairs.begin(), pairs.begin()+k);
        sort(topK.begin(), topK.end(), comp);
        vector<int> ans;
        for(auto& it: topK) {
            ans.push_back(it.first);
        }
        return ans;
    }
};