class Solution {
public:
    // LURD
    int dx[8] = {0, -1, -1, -1, 0, +1, +1, +1};
    int dy[8] = {-1, -1, 0, +1, +1, +1, 0, -1};

    bool isValid(int ni, int nj, int n, int m) {
        return ni >= 0 && ni < n && nj >= 0 && nj < m;
    }

    int getSum(int i, int j, int n, int m, vector<vector<int>>& img) {
        int sum = img[i][j];
        int count = 1;
        for(int ind=0; ind<8; ind++) {
            int ni = i + dx[ind];
            int nj = j + dy[ind];
            if(isValid(ni, nj, n, m)) {
                count++;
                sum += img[ni][nj];
            }
        }
        return sum / count;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = getSum(i, j, n, m, img);
            }
        }
        return ans;
    }
};