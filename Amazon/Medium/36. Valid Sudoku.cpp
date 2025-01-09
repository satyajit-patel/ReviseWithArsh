class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<int> rows[9];
        set<int> cols[9];
        set<int> minGrid[3][3];
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char ch = board[i][j];
                if(ch != '.') {
                    int ele = ch - '0';

                    if(cols[j].count(ele) || rows[i].count(ele) || minGrid[i/3][j/3].count(ele)) {
                        return false;
                    }

                    cols[j].insert(ele);
                    rows[i].insert(ele);
                    minGrid[i/3][j/3].insert(ele);
                }
            }
        }
        return true;
    }
};