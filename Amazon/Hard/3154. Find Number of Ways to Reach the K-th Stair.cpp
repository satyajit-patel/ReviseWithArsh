class Solution {
public:
    long long mypow(long long base, int power) {
        long long mul = 1;
        while(power) {
            if(power & 1) {
                mul *= base;
            }

            base *= base;
            power >>= 1;
        }
        return mul;
    }

    unordered_map<string, int> dp;
    vector<int> powerOf;

    int state(int i, int jump, int canJump, int k) {
        //base case
        if(i > k+1) {
            return 0;
        }
        string key = to_string(i) + to_string(jump) + to_string(canJump);
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }

        // transition
        int ways = 0;
        if(i == k) {
            ways++;
            // no return here as we can again come-back here
        }
        if(canJump) {
            ways += state(i-1, jump, 0, k);
        }
        ways += state(i+powerOf[jump], jump+1, 1, k);

        // return case
        dp[key] = ways;
        return ways;
    }

    int waysToReachStair(int k) {
        // int == 2^31 - 1
        powerOf.clear();
        powerOf.resize(32);
        for(int i=0; i<32; i++) {
            // pow() is O(log(power)) either
            powerOf[i] = mypow(2, i); // O(log(power))
        }
        dp.clear();
        int ans = state(1, 0, 1, k);
        return ans;
    }
};