class Solution {
public:
    int dx[4] = {0, -1, 0, 1}; // LURD
    int dy[4] = {-1, 0, 1, 0};

    bool isValid(int i, int j, vector<vector<int>>& mat) {
        return i>=0 && i<mat.size() && j>=0 && j <mat[0].size();
    }

    void bfs(int i, int j, vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        q.push({i, j});
        mat[i][j] = 0;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            i = it.first;
            j = it.second;
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, mat) && mat[ni][nj] == 1) {
                    q.push({ni, nj});
                    mat[ni][nj] = 0;
                }
            }
        }
    }

    int getIslandCount(vector<vector<int>>& grid) {
        vector<vector<int>> mat = grid;
        int cc = 0;
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[i].size(); j++) {
                if(mat[i][j] == 1) {
                    cc++;
                    bfs(i, j, mat);
                }
            }
        }
        return cc;
    }

    int minDays(vector<vector<int>>& grid) {
        int cc = getIslandCount(grid);
        if(cc == 0 || cc > 1) {
            return 0;
        }
        // we can break any island within 2 days that's for sure
        // but can we do that with in one day
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    cc = getIslandCount(grid);
                    if(cc == 0 || cc > 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};