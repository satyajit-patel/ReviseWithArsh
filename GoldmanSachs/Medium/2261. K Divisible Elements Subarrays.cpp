class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        // 1 <= n <= 100 // O(n^4)
        set<vector<int>> ans;
        for(int i=0; i<n; i++) {
            int div = 0;
            vector<int> temp;
            for(int j=i; j<n; j++) {
                div += (nums[j] % p == 0);
                temp.push_back(nums[j]);
                if(div <= k) {
                    // for(auto& it: temp) {
                    //     cout << it << " ";
                    // }
                    // cout << endl;
                    ans.insert(temp);
                } else {
                    break;
                }
            }
        }
        return ans.size();
    }
};