class Solution {
public:
    vector<long long> sum; // Use long long for large sums
    long long totalCoordinatePoints;
    vector<vector<int>> rects;

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        totalCoordinatePoints = 0;
        for(auto& it : rects) {
            int x1 = it[0], y1 = it[1], x2 = it[2], y2 = it[3];
            totalCoordinatePoints += (long long)(x2 - x1 + 1) * (y2 - y1 + 1);
            sum.push_back(totalCoordinatePoints);
        }
    }
    
    vector<int> pick() {
        int randomCoordinate = std::rand() % totalCoordinatePoints;

        // Find the rectangle using binary search
        int index = upper_bound(sum.begin(), sum.end(), randomCoordinate) - sum.begin();

        // Pick a random point inside the chosen rectangle
        auto& rect = rects[index];
        int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
        int x = x1 + std::rand() % (x2 - x1 + 1);
        int y = y1 + std::rand() % (y2 - y1 + 1);
        return {x, y};
    }
};