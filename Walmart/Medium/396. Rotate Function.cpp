class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        /*
            Input: nums = [4,3,2,6]
            Output: 26
            Explanation:
            F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
            F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
                // pattern
                 = f(0) + totSum - (nums[n-1] * n)
                 = 25 + 15 - 24
                 = 16
            F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
            F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
            So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
        */
        int n = nums.size();
        int totSum = 0;
        int prevSum = 0;
        for(int i=0; i<n; i++) {
            totSum += nums[i];
            prevSum += (i * nums[i]);
        } 
        int maxi = INT_MIN;
        for(int i=n-1; i>=0; i--) {
            int curSum = prevSum + totSum - (nums[i] * n);
            maxi = max(maxi, curSum);
            prevSum = curSum;
        }
        return maxi;
    }
};