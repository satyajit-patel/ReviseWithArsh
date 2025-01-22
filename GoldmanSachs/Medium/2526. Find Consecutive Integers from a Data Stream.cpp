class DataStream {
public:
    deque<int> last;
    int window;
    deque<int> now;

    // bool f() { // TLE
    //     int i = last.size() - 1;
    //     int j = cur.size() - 1;
    //     int len = 0;
    //     // 1 2 3 4 5 6 7 8 9 10
    //     int start = last.size() - window;
    //     int begin = cur.size() - window; 
    //     while(len++ < window) {
    //         if(last[i--] != cur[j--]) {
    //             return false;
    //         }
    //         if(last[start++] != cur[begin++]) {
    //             return false;
    //         }
    //         int mid1 = (start + i) / 2;
    //         int mid2 = (begin + j) / 2;
    //         if(last[mid1] != cur[mid2]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    DataStream(int value, int k) {
        deque<int> temp(k, value);
        last = temp;
        window = k;
        now.clear();
    }
    
    bool consec(int num) {
        // cur.push_back(num);
        // if(cur.size() >= last.size()) {
        //     if(f()) { // O(n)
        //         return true;
        //     }
        // }
        now.push_back(num);
        if(now.size() > window) {
            now.pop_front();
        }
        if(now.size() == last.size()) {
            return now == last; // O(1)
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */