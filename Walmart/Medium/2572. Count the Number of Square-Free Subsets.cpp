class Solution {
public:
    vector<vector<int>> grid;
    int mod = 1e9+7;

    unordered_set<int> getFlagedNum() {
        unordered_set<int> flagedNum;
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for(int i=1; i<=30; i++) {
            int num = i;
            for(auto& it: primes) {
                int count = 0;
                while(num % it == 0) {
                    count++;
                    num /= it;
                }
                if(count > 1) {
                    flagedNum.insert(i);
                    break;
                }
                if(num == 1) {
                    break;
                }
            }
        }
        return flagedNum;
    }

    void f(int i, vector<int>& filteredNums, vector<int>& temp) {
        // base case
        if(i >= filteredNums.size()) {
            if(!temp.empty()) {
                grid.push_back(temp);
            }
            return;
        }

        // transition
        temp.push_back(filteredNums[i]);
        f(i+1, filteredNums, temp);
        temp.pop_back();
        f(i+1, filteredNums, temp);
    }

    long long my_pow(long long base, long long power) {
        long long prod = 1;
        while(power) {
            if(power & 1) {
                prod = ((prod % mod) * (base % mod)) % mod;
            }
            base = ((base % mod) * (base % mod)) % mod;
            power >>= 1;
        }
        return prod;
    }

    int squareFreeSubsets(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& it: nums) {
            mp[it]++;
        }
        unordered_set<int> flagedNum = getFlagedNum();
        vector<int> filteredNums;
        for(auto& it: mp) {
            int ele = it.first;
            if(flagedNum.find(ele) == flagedNum.end()) {
                filteredNums.push_back(ele);
            }
        }
        // for(auto& it: filteredNums) {
        //     cout << it << " ";
        // }
        // cout << "\n---- \n";
        grid.clear();
        vector<int> temp;
        f(0, filteredNums, temp);
        int ans = 0;
        for(auto& it: grid) {
            bool isGood = true;
            for (int i = 0; i < it.size(); i++) {
                // cout << it[i] << " ";
                for (int j = i + 1; j < it.size(); j++) {
                    if (gcd(it[i], it[j]) > 1) {
                        // gcd > 1 i.e they have common num which will become square together
                        // so we will avoid that
                        isGood = false;
                        break;
                    }
                }
                if (!isGood) {
                    break;
                }
            }
            // cout << endl;
            if(isGood) {
                long long x = 1LL;
                for(int i=0; i<it.size(); i++) {
                    if(it[i] == 1) {
                        // 1 is a special case
                        // long long totSubset = 1LL * (1 << mp[it[i]]) - 1;
                        long long totSubset = my_pow(2, mp[it[i]]) - 1; // substract the empty subset
                        x = (1LL * (x % mod) * (totSubset % mod)) % mod;
                    } else {
                        // x *= mp[it[i]];
                        x = ((x % mod) * (mp[it[i]] % mod)) % mod;
                    }
                }
                ans += x;
                ans %= mod;
            }
        }
        return ans % mod;
    }
};