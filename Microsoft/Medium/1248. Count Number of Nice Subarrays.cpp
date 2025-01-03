// similar
// https://cses.fi/problemset/result/10721914/
// https://cses.fi/problemset/result/10722004/
// https://cses.fi/problemset/result/10722117/
// https://cses.fi/problemset/task/2428


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int nice = 0;

        int sum = 0;
        map<int, int> mp;
        mp[sum]++;
        
        for(int i=0; i<n; i++) {
            sum += (nums[i] & 1);

            if(mp[sum - k]) {
                nice += mp[sum - k]; // sum might get repeated, else would just nice++
            }

            mp[sum]++;
        }

        return nice;
    }
};