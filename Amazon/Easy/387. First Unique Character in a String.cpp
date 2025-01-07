class Solution {
public:
    int firstUniqChar(string& s) {
        map<int, int> mp;
        for(auto& it: s) {
            mp[it]++;
        }
        for(int i=0; i<s.size(); i++) {
            if(mp[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};