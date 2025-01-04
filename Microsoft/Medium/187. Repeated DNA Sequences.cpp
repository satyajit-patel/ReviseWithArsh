class Solution {
public:
    vector<string> findRepeatedDnaSequences(string& s) {
        vector<string> ans;
        int n = s.size();

        map<string, int> mp;

        for(int i=0,init=0; i<n; i++) {
            if(i-init+1 == 10) {
                string dna = s.substr(init++, 10);
                mp[dna]++;
            }
        }
        for(auto& it: mp) {
            if(it.second > 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};