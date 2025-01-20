class Solution {
public:
    int countCollisions(string d) {
        int ans = 0;
        vector<pair<char, int>> nums;
        for(int i=0; i<d.size(); i++) {
            int count = 1;
            while(i+1 < d.size() && d[i+1] == d[i]) {
                count++;
                i++;
            }
            nums.push_back({d[i], count});
        }
        // for(auto& it: nums) {
        //     cout << it.first << it.second << " ";
        // }
        for(int i=0; i<nums.size()-1; i++) {
            // 3 cases
            if(nums[i].first == 'R' && nums[i+1].first == 'L') { // RRRRLLLL
                ans += nums[i].second + nums[i+1].second;
            } else if(nums[i].first == 'S' && nums[i+1].first == 'L') { // SLLLL
                ans += nums[i+1].second;
            } else if(nums[i].first == 'R' && nums[i+1].first == 'S') { // RRRRS
                ans += nums[i].second;
            }
        }
        return ans;
    }
};