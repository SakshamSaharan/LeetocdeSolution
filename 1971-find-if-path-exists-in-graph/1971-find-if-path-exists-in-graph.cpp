class Solution {
public:
    bool dfs(int src,int dest,vector<bool>& visited,vector<vector<int>>& adj){
        if(src == dest) return true;
        visited[src] = true;

        for(int v : adj[src]){
            if(! visited[v]){
                if(dfs(v,dest,visited,adj)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);

        return dfs(source,destination,visited,adj);
    }
};