class Solution {
    int bfs(vector<vector<int>>& grid, queue<pair<pair<int,int>,int>> q,vector<int> dx, vector<int> dy){
        int n = grid.size();
        int  m = grid[0].size();
        int timemax = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            timemax = max(timemax,time);
            q.pop();
    
            for(int i =0;i<4;i++){
                int newrow = row + dx[i];
                int newcol = col + dy[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==1){
                    grid[newrow][newcol] = 3;
                    q.push({{newrow,newcol},time+1});
                }
            }
            
        }
        return timemax;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int  m = grid[0].size();
        // vector<int> visited(n,vector<int>(m,0));
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0, 1,-1};
        
        // {{row,col},time}
        queue<pair<pair<int,int>,int>> q;
        // vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] == 2){
                    // visited[i][j] = 1;
                    q.push({{i,j},0});
                    grid[i][j] = 3;
                }
            }
        }
        int time =0;
        time = bfs(grid,q,dx,dy);
        
        for(int i = 0;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] == 1){
                    return -1; 
                }
            }
        }
        return time;
    }
};