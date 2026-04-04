// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int row=grid.size();
        int col=grid[0].size();
        //vector<vector<bool>> vis(row,vector<bool>(cols,false));
        set<vector<pair<int,int>>> st;
        queue<pair<int,int>> que;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    vector<pair<int,int>> vec;
                    int base_row=i;
                    int base_col=j;
                    que.push({i,j});
                    while(!que.empty()){
                        int r=que.front().first;
                        int c=que.front().second;
                        vec.push_back({r-base_row,c-base_col});
                        que.pop();
                        int dx[5]={1,0,-1,0,1};
                        for(int k=0;k<4;k++){
                            int adj_row=r+dx[k];
                            int adj_col=c+dx[k+1];
                            if(adj_row>=0&&adj_row<row&&adj_col>=0&&adj_col<col
                            &&grid[adj_row][adj_col]==1){
                                grid[adj_row][adj_col]=0;
                                que.push({adj_row,adj_col});
                            }
                        }
                        
                    }
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
