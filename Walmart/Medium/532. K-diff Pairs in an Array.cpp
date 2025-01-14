class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;
        while(i < n && j < n) {
            int diff = nums[j] - nums[i];
            if(i == j) {
                j++;
            } else if(diff == k) {
                ans++;
                i++;
                // skip the duplicates
                while(i < n && nums[i] == nums[i-1]) {
                    i++;
                }
            } else if(diff < k) {
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};