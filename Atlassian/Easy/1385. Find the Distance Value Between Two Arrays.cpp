class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for(int i=0; i<arr1.size(); i++) {
            bool isGood = true;
            for(int j=0; j<arr2.size(); j++) {
                int dist = abs(arr1[i] - arr2[j]);
                if(dist <= d) {
                    isGood = false;
                    break;
                }
            }
            if(isGood) {
                count++;
            }
        }
        return count;
    }
};