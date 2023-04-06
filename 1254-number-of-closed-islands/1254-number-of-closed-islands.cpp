class Solution {
public:
    
    void islands(int row,int col, int n,int m ,vector<vector<int>> &grid,vector<int>&dx , vector<int>& dy){
        
        grid[row][col] = 3;
        
        for(int i =0;i<4;i++){
            int newrow = row + dx[i];
            int newcol = col + dy[i];
            
            if(newrow>=0 && newrow<n && newcol >=0 && newcol <m && grid[newrow][newcol] == 0){
                islands(newrow,newcol,n,m,grid,dx,dy);
            }
        }
    }
    
    void dfs(int row,int col, int n,int m ,vector<vector<int>> &grid,vector<int>&dx , vector<int>& dy){
        
        grid[row][col] = 2;
        
        for(int i =0;i<4;i++){
            int newrow = row + dx[i];
            int newcol = col + dy[i];
            
            if(newrow>=0 && newrow<n && newcol >=0 && newcol <m && grid[newrow][newcol] == 0){
                dfs(newrow,newcol,n,m,grid,dx,dy);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
       // first ill change boundry 0 to 2
        vector<int> dx = {0,0,-1,1};
        vector<int> dy ={-1,1,0,0};
        int n = grid.size();
        int m = grid[0].size();
        
        
    
       for(int j = 0;j<m;j++){
            if(grid[0][j]== 0){
                dfs(0,j,n,m,grid,dx,dy);
            }
            
            if(grid[n-1][j]== 0){
                dfs(n-1,j,n,m, grid,dx,dy);
            }
        }
        
        
        for(int i = 0;i<n;i++){
            if(grid[i][0]==0){
                dfs(i,0,n,m,grid,dx,dy);
            }
            
            if(grid[i][m-1]== 0){
                dfs(i,m-1,n,m, grid,dx,dy);
            }
        }
        
        int ans = 0;  
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    islands(i,j,n,m,grid,dx,dy);
                }
            }
        }
        return ans;
    }
};