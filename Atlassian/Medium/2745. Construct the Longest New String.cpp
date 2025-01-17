class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x == y) {
            return (2 * x) + (2 * y) + (2 * z);
        } else {
            int mini = min(x, y);
            return (2 * mini) + (2 * (mini+1)) + (2 * z);
        }
    }
};