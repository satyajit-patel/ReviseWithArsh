class Solution {
public:
    vector<vector<int>> ans;

    void f(int i, int k, int sum, vector<int>& nums, vector<int>& temp) {
        // base case
        if(sum == 0 && k == 0) {
            if(!temp.empty()) {
                ans.push_back(temp);
            }
            return;
        }
        if(i >= 9) {
            return;
        }

        // transition
        // take
        if(sum - nums[i] >= 0 && k) {
            temp.push_back(nums[i]);
            f(i+1, k-1, sum-nums[i], nums, temp);
            temp.pop_back();
        }
        // not take
        f(i+1, k, sum, nums, temp);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int> temp, nums;
        for(int i=1; i<=9; i++) {
            nums.push_back(i);
        }
        f(0, k, n, nums, temp);
        return ans;
    }
};