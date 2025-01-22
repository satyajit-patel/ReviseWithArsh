class Solution {
public:
    vector<string> keyboard = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    void f(int i, string digits, string& temp) {
        // base case
        if(i >= digits.size()) {
            if(!temp.empty()) {
                ans.push_back(temp);
            }
            return;
        }

        // transition
        int index = digits[i] - '0';
        string word = keyboard[index];
        for(auto& it: word) {
            temp += it;
            f(i+1, digits, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        ans.clear();
        string temp = "";
        f(0, digits, temp);
        return ans;
    }
};