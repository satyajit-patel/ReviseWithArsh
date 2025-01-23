// https://www.geeksforgeeks.org/problems/run-length-encoding/1
class Solution {
  public:
    string encode(string s) {
        int ch = '$'; // dollar sign one time
        int count = 0;
        string ans = "";
        for(auto& it: s) {
            if(ch == '$' || it == ch) {
                ch = it;
                count++;
            } else {
                ans += ch;
                ans += to_string(count);
                
                ch = it;
                count = 1;
            }
        }
        ans += ch;
        ans += to_string(count);
        return ans;
    }
};