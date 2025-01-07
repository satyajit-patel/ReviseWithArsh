class Solution {
public:
    void floydWarshall(vector<vector<long long>>& grid) {
        for(int k=0; k<26; k++) {
            for(int u=0; u<26; u++) {
                for(int v=0; v<26; v++) {
                    grid[u][v] = std::min(grid[u][v], grid[u][k] + grid[k][v]); // go via k
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<long long>> grid(26, vector<long long>(26, INT_MAX));

        for(int i=0; i<original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int c = cost[i];
            grid[u][v] = std::min(grid[u][v], (long long)c);
        }

        // all source shortest path
        floydWarshall(grid);

        long long minCost = 0;
        for(int i=0; i<source.size(); i++) {
            if(source[i] != target[i]) {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                int c = grid[u][v];
                if(c == INT_MAX) {
                    return -1;
                } else {
                    minCost += c;
                }
            }
        }
        return minCost;
    }
};