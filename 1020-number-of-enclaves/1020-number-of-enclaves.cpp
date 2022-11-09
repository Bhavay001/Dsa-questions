class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid,vector<int> dx,vector<int> dy){
        visited[row][col] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i =0;i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,visited,grid,dx,dy);
            }
        }
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        // similar to surrounded regions we will check for boundry 1s and make a dfs call to the neg=ighbouring 1s
        // we will all negighbouring 1s with the boundry 1s as visited the at last check for 1s which are not visited
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        for(int j =0;j<m;j++){
            if(!visited[0][j] && grid[0][j]==1){
                dfs(0,j,visited,grid,dx,dy);
            }
            if(!visited[n-1][j] && grid[n-1][j]==1){
               dfs(n-1,j,visited,grid,dx,dy); 
            }
        }
        
        for(int i =0;i<n;i++){
            if(!visited[i][0] && grid[i][0]==1){
                dfs(i,0,visited,grid,dx,dy);
            }
            if(!visited[i][m-1] && grid[i][m-1]==1){
               dfs(i,m-1,visited,grid,dx,dy); 
            }
        }
        int count = 0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};