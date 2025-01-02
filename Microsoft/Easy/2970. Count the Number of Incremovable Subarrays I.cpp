class Solution {
public:
    bool isGood(int i, int j, int n, vector<int>& nums) {
        int lastEle = -1;
        for(int x=0; x<n; x++) {
            if(x >= i && x <= j) {
                continue;
            }
            int curEle = nums[x];
            if(curEle <= lastEle) {
                return false;
            }
            lastEle = curEle;
        }
        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(isGood(i, j, n, nums)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};