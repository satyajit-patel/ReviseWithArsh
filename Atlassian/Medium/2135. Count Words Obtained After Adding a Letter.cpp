class Solution {
public:
    int wordCount(vector<string>& s, vector<string>& t) {
        int ans = 0;

        set<string> st;
        for(int i=0; i<s.size(); i++) {
            sort(s[i].begin(), s[i].end());
            st.insert(s[i]);
        }
        for(int i=0; i<t.size(); i++) {
            string temp = t[i];
            sort(temp.begin(), temp.end());
            bool flag = false;
            for(int j=0; j<temp.size(); j++) {
                string target = temp.substr(0, j) + temp.substr(j+1); // del 1 char at a time
                if(st.count(target)) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                ans++;
            }
        }
       
        return ans;
    }
};