// https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1
class Solution {   
public:
    string ans;
    bool flag;
    
    void f(int i, char prev, string& s, string& temp, set<char>& st) {
        // cout << temp << endl;
        // base case
        if(flag) {
            return;
        }
        if(temp.size() == s.size()+1) {
            ans = temp;
            flag = true;
        }
        
        // transition
        for(char ele='1'; ele<='9'; ele++) {
            if(prev == '$') {
                temp += ele;
                st.insert(ele);
                f(i+1, (i<s.size()) ? s[i] : '#', s, temp, st); // '#' means end
                temp.pop_back();
                st.erase(ele); // as there shouldn't be any duplicate element
            } else if(prev == 'I') {
                if(ele > temp.back() && (st.find(ele) == st.end())) {
                    temp += ele;
                    st.insert(ele);
                    f(i+1, (i<s.size()) ? s[i] : '#', s, temp, st);
                    temp.pop_back();
                    st.erase(ele);
                }
            } else {
                if(ele < temp.back() && (st.find(ele) == st.end())) {
                    temp += ele;
                    st.insert(ele);
                    f(i+1, (i<s.size()) ? s[i] : '#', s, temp, st);
                    temp.pop_back();
                    st.erase(ele);
                }
            }
        }
    }

    string printMinNumberForPattern(string S){
        ans.clear();
        flag = false;
        string temp;
        set<char> st;
        f(0, '$', S, temp, st); // dollar sign one time
        return ans;
    }
};
