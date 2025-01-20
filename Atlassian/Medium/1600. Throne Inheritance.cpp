class ThroneInheritance {
public:
    unordered_set<string> st;
    unordered_map<string, vector<string>> mp;
    string root;

    ThroneInheritance(string kingName) {
        this->st.clear();
        this->mp.clear();
        this->root = kingName;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        st.insert(name);
    }

    void dfs(string root, vector<string>& ans) {
        if(!st.count(root)) {
            ans.push_back(root);
        }
        for(auto& child: mp[root]) {
            dfs(child, ans);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(this->root, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */