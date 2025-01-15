class Solution {
public:
    string frequencySort(string& s) {
        string ans = "";
        map<char, int> mp;
        for(auto& it: s) {
            mp[it]++;
        }
        priority_queue<pair<int, char>> maxHeap;
        for(auto& it: mp) {
            maxHeap.push({it.second, it.first});
        }
        while(!maxHeap.empty()) {
            auto it = maxHeap.top();
            maxHeap.pop();
            int x = it.first;
            char ch = it.second;
            string temp(x, ch);
            ans += temp;
        }
        return ans;
    }
};