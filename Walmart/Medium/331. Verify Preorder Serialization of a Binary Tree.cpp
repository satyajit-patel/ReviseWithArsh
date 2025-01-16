class Solution {
public:
    bool isValidSerialization(string& preorder) {
        vector<string> ds;
        stringstream ss(preorder);
        while(ss.good()) {
            string s;
            getline(ss, s, ',');
            ds.push_back(s);
        }

        int slots = 1;
        for(auto& it: ds) {
            if(slots <= 0) {
                return false;
            }
            slots += (it == "#") ? -1 : 1;
        }
        return slots == 0;
    }
};