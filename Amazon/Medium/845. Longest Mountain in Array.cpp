class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        for(int i=1; i<n-1; i++) {
            // find thge candidate
            if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])) {
                int leftGuys = 0;
                int frontGuy = i;
                for(int left=i-1; left>=0; left--) {
                    if(arr[left] < arr[frontGuy]) {
                        leftGuys++;
                        frontGuy = left;
                    } else {
                        break;
                    }
                }
                int rightGuys = 0;
                frontGuy = i;
                for(int right=i+1; right<n; right++) {
                    if(arr[right] < arr[frontGuy]) {
                        rightGuys++;
                        frontGuy = right;
                    } else {
                        break;
                    }
                }
                int totGuys = leftGuys + rightGuys + 1; // with mid guy
                maxi = max(maxi, totGuys);
            }
        }
        return maxi;
    }
};