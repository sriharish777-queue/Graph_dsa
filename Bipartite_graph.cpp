class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(V);
        int row=edges.size();
        int col=edges[0].size();
        for(int i=0;i<row;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(V,-1);
        color[0]=0;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int node=que.front();
            que.pop();
            for(auto it:adj[node]){
                if(color[it]==-1){
                    que.push(it);
                    if(color[node]==0){
                        color[it]=1;
                    }
                    else{
                        color[it]=0;
                    }
                }
                else{
                    if(color[node]==color[it]){
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
};
