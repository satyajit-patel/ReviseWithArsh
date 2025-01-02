class Solution {
public:
    void f(int i, int k, vector<int>& circle) {
        // base case
        if(circle.size() == 1) {
            return;
        }

        // transition
        int targetIndex = (i + k - 1) % circle.size();
        circle.erase(circle.begin()+targetIndex);
        f(targetIndex, k, circle);
    }

    int findTheWinner(int n, int k) {
        vector<int> circle;
        for(int i=0; i<n; i++) {
            circle.push_back(i+1);
        }
        f(0, k, circle);
        return circle[0];
    }
};