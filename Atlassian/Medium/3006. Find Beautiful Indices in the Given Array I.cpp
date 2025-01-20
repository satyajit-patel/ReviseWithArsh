class Solution {
public:
    vector<int> find(string a, string s) {
        vector<int> ans;
        while(1) {
            int index = s.find(a);
            if(index == -1) {
                break;
            }
            ans.push_back(index);
            s[index] = '$';
        }
        return ans;
    }

    bool f(int num, vector<int>& nums, int k) {
            // 4 5 iIndex
            // 6 7 jIndex diff will increase moving forward if diff is -ve
            // but
            // 6 7 iIndex
            // 4 5 jIndex diff will decrease moving forward if diff is +ve
            int i = 0;
            int j = nums.size() - 1;
            while(i <= j) {
                int mid = (i + j) / 2;
                int diff = num - nums[mid];
                int x = abs(diff);
                if(x <= k) {
                    return true;
                } else {
                    if(diff < 0) {
                        j = mid - 1;
                    } else {
                        i = mid + 1;
                    }
                }
            }
            return false;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> aIndex = find(a, s); 

        vector<int> bIndex = find(b, s);
        vector<int> beautiful;
        for(auto& it: aIndex) { // O(n * logn)

            // if(f(it, bIndex, k)) {
            //     beautiful.push_back(it);
            // }

                        // or

            /*
                |it - x| <= k
                if we open the mod then it will have 2 possibility
                (it - x) <= k and (-it + x) <= k
                x >= (it - k) and x <= (k + it)

                so to be beautiful element "it" has to find a partner
                which is >= (it - k) ans <= (k + it)

                let 
                    it = 16
                    k = 15
                    so x has to  (1) <= x <= (31) 
            */
            int minLimit = it - k;
            int maxLimit = it + k;
            auto lb = lower_bound(bIndex.begin(), bIndex.end(), minLimit);
            if((lb != bIndex.end()) && (*lb <= maxLimit)) {
                beautiful.push_back(it);
            }
        }
        return beautiful;
    }
};