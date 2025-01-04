class Solution {
public:
    vector<int> getDijkstra(int node, int n, vector<pair<int, int>> adj[]) {
        vector<int> dist(n, INT_MAX);
        dist[node] = 0;
        queue<pair<int, int>> q;
        q.push({node, dist[node]});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int curNode = it.first;
            int curCost = it.second;

            for(auto& child: adj[curNode]) {
                int adjNode = child.first;
                int adjCost = child.second;
                int newCost = curCost + adjCost;
                if(newCost < dist[adjNode]) {
                    dist[adjNode] = newCost;
                    q.push({adjNode, dist[adjNode]});
                }
            }
        }

        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> adj[n];
        for(auto& it: edges) {
            int u = it[0];
            int v = it[1];
            int d = it[2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        vector<vector<int>> temp;
        for(int node=0; node<n; node++) {
            vector<int> dijkstra = getDijkstra(node, n, adj);
            temp.push_back(dijkstra);
        }
        int mini = INT_MAX;
        int ans = -1;
        for(int node=0; node<n; node++) {
            int cityCount = 0;
            for(auto& it: temp[node]) {
                if(it <= distanceThreshold) {
                    cityCount++;
                }
            }
            if(cityCount <= mini) {
                mini = cityCount;
                ans = node;
            }
        }
        return ans;
    }
};