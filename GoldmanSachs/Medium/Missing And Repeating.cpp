// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        map<int, int> mp;
        for(auto& it: arr) {
            mp[it]++;
        }
        
        // 6 5 8 7 1 4 1 3 2
        // 1 2 3 4 5 6 7 8
        
        vector<int> ans;
        int x = 1;
        bool flag = true;
        int twice = -1;
        int missing = -1;
        for(auto& it: mp) {
            // cout << it.first << " " << it.second << endl;
            if(it.second == 2) {
                twice = it.first;
                // ans.push_back(it.first);
            }
            if(it.first != x && flag) {
                // ans.push_back(x);
                missing = x;
                flag = !flag;
            }
            // if(ans.size() == 2) {
            //     return ans;
            // }
            x++;
        }
        // cout << "HI\n";
        // ans.push_back(x);
        // return ans;
        if(missing == -1) {
            missing = x;
        }
        return {twice, missing};
    }
};