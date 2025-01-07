class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        /*
            1 5 1 1 6 4
            1 1 1 4 5 6 // sorted

            
        */
        int n = nums.size();
        vector<int> ans(nums);
        std::sort(ans.begin(), ans.end());

        int mid = (n-1) / 2;
        int end = n - 1;
        
        for(int i=0; i<n; i++) {
            nums[i] = (i & 1) ? ans[end--] : ans[mid--];
        }
    }
};