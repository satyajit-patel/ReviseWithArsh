class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> minHeap;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            minHeap.push({-nums[i], i});
        }
        while(k--) {
            auto it = minHeap.top();
            minHeap.pop();
            int ele = -it.first;
            int ind = it.second;
            ele++;
            nums[ind] = ele;
            minHeap.push({-ele, ind});
        }
        long long prod = 1;
        int mod = 1e9 + 7;
        for(auto& it: nums) {
            prod *= it;
            prod %= mod;
        }
        return prod;
    }
};