class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxi = INT_MIN;
        for(int i=0,init=0; i<nums.size(); i++) {
            mp[nums[i]]++;
            while(mp[nums[i]] > k) {
                mp[nums[init++]]--;
            }
            maxi = max(maxi, i-init+1);
        }
        return maxi;
    }
};