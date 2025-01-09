// https://www.geeksforgeeks.org/problems/phone-directory4628/1
class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string& s) {
        vector<vector<string>> ans;
        string target = "";
        
        for (char ch : s) { // O(|s| = 6)
            target += ch;
            set<string> tempSet; // Use set to ensure uniqueness and sorting
            
            for (int i = 0; i < n; i++) { // O(n = 50)
                // if (contact[i].find(target) == 0) { // Check prefix match
                //     tempSet.insert(contact[i]);
                // }
                
                // .substr() doesn't scan the entine string
                // .find() = O(n) where n is length of string
                // .substr() = O(k) where k is length of substring only
                
                if (contact[i].substr(0, target.size()) == target) {
                    tempSet.insert(contact[i]);
                }
            }
            
            if (tempSet.empty()) {
                ans.push_back({"0"});
            } else {
                ans.push_back(vector<string>(tempSet.begin(), tempSet.end()));
            }
        }
        
        return ans;
    }
};
