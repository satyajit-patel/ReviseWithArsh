class KthLargest {
public:
    int k;
    priority_queue<int> minHeap;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto& it: nums) {
            minHeap.push(-it);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(-val);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
        return -minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */