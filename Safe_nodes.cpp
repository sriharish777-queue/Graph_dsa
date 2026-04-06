class Solution {
  public:
    bool dfs(int node,vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &path_vis,
    vector<bool> &check){
        vis[node]=true;
        path_vis[node]=true;
        // move to adjacent outgoing neighbours
        for(auto it:adj[node]){
            //if the node is not visited already
            if(!vis[it]){
                if(dfs(it,adj,vis,path_vis,check)==true){
                    return true;
                }
            }
            // if the node is already visited but the path_vis for that node is 1 then
            //cycle is present
            else if(path_vis[it]==true){
                return true;
            }
        }
        //backtrack and check if there any neighbours forming cycle
        //check[node]=true indicates the partciular node is a safe node bcoz it will never 
        //form a cycle
        check[node]=true;
        //backtrack
        path_vis[node]=false;
        return false;
        
    }
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        int row=edges.size();
        vector<vector<int>> adj(V);
        vector<bool> vis(V,false);
        vector<bool> path_vis(V,false);
        vector<int> safe_nodes;
        vector<bool> check(V,false);
        for(int i=0;i<row;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,path_vis,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==true){
                safe_nodes.push_back(i);
            }
        }
        return safe_nodes;
    }
};
