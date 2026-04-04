class Solution {
  private:
    bool detect_cyc(int node,vector<bool> &vis,vector<vector<int>> &adj){
        vis[node]=true;
        queue<pair<int,int>> que;
        que.push({node,-1});
        while(!que.empty()){
            int start=que.front().first;
            int parent=que.front().second;
            que.pop();
            // visit the neighbouring nodes
            for(auto it:adj[start]){
                if(!vis[it]){
                    vis[it]=true;
                    que.push({it,start});
                }
                else if(parent!=it){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        int size=edges.size();
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect_cyc(i,vis,adj)==true){
                    return true;
                }
            }
        }
        return false;
    }
};
