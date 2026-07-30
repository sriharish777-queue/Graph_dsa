class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        // topo u and v u should appear before v
        vector<vector<int>> adj(V);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        vector<int> in_deg(V,0);
        for(int i=0;i<V;i++){
            for(auto &it:adj[i]){
                in_deg[it]++;
            }
        }
        // if particular node ind is 0 store them in the queue
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(in_deg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto &it:adj[node]){
                //reduce the indegree for that particular node
                in_deg[it]--;
                if(in_deg[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
