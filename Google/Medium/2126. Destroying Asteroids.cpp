class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long x = mass;
        for(auto& it: asteroids) {
            if(x >= it) {
                x += it;
            } else {
                return false;
            }
        }
        return true;
    }
};