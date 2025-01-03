class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int midEle = nums[n/2];
        int step = 0;
        for(int i=0; i<n; i++) {
            step += abs(nums[i] - midEle);
        }
        return step;
    }
};