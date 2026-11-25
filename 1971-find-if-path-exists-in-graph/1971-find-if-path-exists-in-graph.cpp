
class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int src, int dest,
             vector<bool>& vis) {
        
        if(src == dest) return true;

        vis[src] = true;

        for(int v : adj[src]) {
            if(!vis[v]) {
                if(dfs(adj, v, dest, vis))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {
        
        vector<vector<int>> adj(n);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        return dfs(adj, source, destination, vis);
    }
};
