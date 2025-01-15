class Solution {
public:
    bool isGood(int x, int y) {
        if(y <= 0.5 * x + 7) {
            return false;
        }
        if(y > x) {
            return false;
        }
        if(y > 100 && x < 100) {
            return false;
        }
        return true;
    }

    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        long long ans = 0;

        unordered_map<int, int> mp;
        for(auto& it: ages) {
            mp[it]++;
        }

        // TLE
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(i != j) {
        //             if(isGood(ages[i], ages[j])) {
        //                 ans += mp[ages[i]] * mp[ages[j]];
        //             }
        //         }
        //     }
        // }

        for(auto& x: mp) {
            for(auto& y: mp) {
                if(isGood(x.first, y.first)) {
                    ans += x.second * (y.second - (x.first == y.first ? 1 : 0));
                }
            }
        }

        return ans;
    }
};