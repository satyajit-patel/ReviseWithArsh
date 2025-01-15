class Solution {
public:
    int dx[4] = {0, -1, 0, 1}; // LURD
    int dy[4] = {-1, 0, 1, 0};

    bool isValid(int i, int j, int n, int m) {
        return i>=0 && i<n && j>=0 && j<m;
    }

    void bfs(int i, int j, vector<vector<char>>& board, int n, int m) {
        board[i][j] = '.';
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            i = it.first;
            j = it.second;
            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isValid(ni, nj, n, m) && board[ni][nj] == 'X') {
                    board[ni][nj] = '.';
                    q.push({ni, nj});
                }
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int cc = 0;
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'X') {
                    cc++;
                    bfs(i, j, board, n, m);
                }
            }
        }
        return cc;
    }
};