/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int n = m.length();
        int i = 1;
        int j = n-2;
        int peakIndex = -1;
        while(i <= j) {
            int mid = (i + j) / 2;
            int x = m.get(mid);
            if(x > m.get(mid-1) && x > m.get(mid+1)) {
                peakIndex = mid;
                break;
            } else if(x > m.get(mid-1)) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        // ascending
        int lo = 0;
        int hi = peakIndex;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            int ele = m.get(mid);
            if(ele == target) {
                return mid;
            } else if(ele > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        // descending
        lo = peakIndex + 1;
        hi = n-1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            int ele = m.get(mid);
            if(ele == target) {
                return mid;
            } else if(ele > target) {
                lo = mid + 1; // carefull
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
};