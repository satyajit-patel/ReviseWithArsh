class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // find nearest coordinate to the circle
        int x = max(x1, min(x2, xCenter));
        int y = max(y1, min(y2, yCenter));

        // find distance using pythagoras theorem
        int b = abs(x - xCenter);
        int h = abs(y - yCenter);
        int d = sqrt((b * b) + (h * h));

        return d <= radius;
    }
};