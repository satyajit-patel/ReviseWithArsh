class Solution {
public:
    int isValid(int ni, int nj, int n, int m) {
        return ni >= 0 && ni < n && nj >= 0 && nj < m;
    }

    int dx[4] = {0, -1, 0, 1}; // LURD
    int dy[4] = {-1, 0, 1, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        // put the affected oranges in queue
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 1;
        int empty = 0;
        int rotten = 2;
        queue<pair<int, pair<int, int>>> q;
        int totOrange = 0, rottenOrange = 0, minTime = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] != empty) {
                    totOrange++;
                }
                if(grid[i][j] == rotten) {
                    q.push({0, {i, j}});
                }
            }
        }

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int t = it.first;
            int i = it.second.first;
            int j = it.second.second;
            rottenOrange++;


            minTime = std::max(minTime, t);
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, n, m) && grid[ni][nj] == fresh) {
                    grid[ni][nj] = rotten;
                    q.push({t+1, {ni, nj}});
                }
            }
        }
        
        if(totOrange != rottenOrange) {
            return -1;
        }
        return minTime;
    }
};