class Solution {
public:
    int dx[4] = {0, -1, 0, 1}; // LURD
    int dy[4] = {-1, 0, 1, 0};

    bool isValid(int i, int j, int n, int m) {
        return i>=0 && i<n && j>=0 && j<m;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int land = 0;
        int water = 1;
        int n = isWater.size();
        int m = isWater[0].size();

        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // multi source bfs
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(isWater[i][j] == water) {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                    isWater[i][j] = 0;
                }
            }
        } 

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int i = it[0];
            int j = it[1];
            int c = it[2];
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, n, m) && !vis[ni][nj]) {
                    q.push({ni, nj, c+1});
                    vis[ni][nj] = 1;
                    isWater[ni][nj] = c+1;
                }
            }
        }

        return isWater;
    }
};