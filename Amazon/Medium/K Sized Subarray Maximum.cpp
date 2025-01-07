// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        
        // O(nlogn)
        // multiset<int> st;
        // for(int i=0,init=0; i<n; i++) {
        //     st.insert(arr[i]);
        //     if(i-init+1 == k) {
        //         ans.push_back(*st.rbegin());
        //         st.erase(st.find(arr[init++]));
        //     }
        // }
        
        // O(n)
        deque<int> dq;
        for(int i=0,init=0; i<n; i++) {
            while(!dq.empty() && arr[i] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(arr[i]);
            if(i-init+1 == k) {
                ans.push_back(dq.front());
                if(arr[init++] == dq.front()) {
                    dq.pop_front();
                }
            }
        }
        
        return ans;
    }
};
