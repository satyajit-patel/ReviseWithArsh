class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi = 0;
        long long sum = 0;
        int n = nums.size();

        // TLE
        // for(int i=0,init=0; i<n; i++) { // O(n)
        //     sum += (long long)nums[i];
        //     if(i-init+1 == k) {
        //         set<int> st(nums.begin()+init, nums.begin()+i+1); // O(k)
        //         // for(auto& it: st) {
        //         //     cout << it << " ";
        //         // }
        //         // cout << endl;
        //         if(st.size() == k) {
        //             maxi = max(maxi, sum);
        //         }
        //         sum -= nums[init++];
        //     }
        // }

        map<int, int> mp;
        for(int i=0,init=0; i<n; i++) { // O(n)
            sum += (long long)nums[i];
            mp[nums[i]]++;
            if(i-init+1 == k) {
                if(mp.size() == k) { // O(1)
                    maxi = max(maxi, sum);
                }
                mp[nums[init]]--;
                if(mp[nums[init]] == 0) {
                    mp.erase(nums[init]);
                }
                sum -= nums[init];
                init++;
            }
        }

        return maxi;
    }
};