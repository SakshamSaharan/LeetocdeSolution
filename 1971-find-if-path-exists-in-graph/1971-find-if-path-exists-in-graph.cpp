class Solution {
public:
    void adjList(vector<vector<int>>& edges,vector<vector<int>>& adj){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void dfs(int u,vector<bool>& visited,vector<vector<int>>& adj){
        visited[u] = true;

        vector<int>neighbour = adj[u];
        for(int v : neighbour){
            if(! visited[v]){
                dfs(v,visited,adj);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        adjList(edges,adj);
        vector<bool>visited(n,false);

        dfs(source,visited,adj);

        return visited[destination] == true;
    }
};