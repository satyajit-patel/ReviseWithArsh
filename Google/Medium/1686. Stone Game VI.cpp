class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int alice = 1;
        int bob = -1;
        int draw = 0;
        int n = aliceValues.size();
        int aliceScore = 0;
        int bobScore = 0;

        vector<vector<int>> nums;
        for(int i=0; i<n; i++) {
            nums.push_back({aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]});
        }
        sort(nums.begin(), nums.end(), greater<vector<int>>());
        for(int i=0; i<n; i++) {
            if(i & 1) {
                bobScore += nums[i][2];
            } else {
                aliceScore += nums[i][1];
            }
        }
       
       
        if(aliceScore > bobScore) {
            return alice;
        }
        if(bobScore > aliceScore) {
            return bob;
        }
        return draw;
    }
};