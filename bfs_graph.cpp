class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> nodes;
        bool vis[];
        queue<int> que;
        que.push(0);
        vis[0]=true;
        while(!que.empty()){
            int start=que.front();
            que.pop();
            nodes.push_back(start);
            // find the neighbours of the start node and mark them as visited and add into queue
            for(auto it:adj[node]){
                if(vis[it]==false){
                    vis[it]=true;
                    que.push(it);
                }
            }
            
        }
        return que;
        
    }
};
