// https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
class Solution {
public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        char order[] = {'!','#','$','%','&','*','?','@','^'};
        vector<char> ans;
        set<char> a(nuts, nuts+n);
        set<char> b(bolts, bolts+n);
        for(auto& it: order) {
            if(a.count(it) && b.count(it)) {
                ans.push_back(it);
            }
        }
        for(int i=0; i<n; i++) {
            nuts[i] = bolts[i] = ans[i];
        }
    }
};