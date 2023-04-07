class Solution {
public:

    void enclave(int row,int col,int n ,int m,int &ans, vector<vector<int>>& grid, vector<int>&dx, vector<int> &dy){
        grid[row][col]  =2;
        ans++;
        for(int i =0;i<4;i++){
            int newrow = row + dx[i];
            int newcol = col + dy[i];
            
            if(newrow>=0 && newrow < n && newcol >=0 && newcol <m && grid[newrow][newcol] ==1){
                enclave(newrow,newcol,n,m,ans,grid,dx,dy);
            }
        }
    }
    
    void solve(int row,int col,int n ,int m,vector<vector<int>>& grid, vector<int>&dx, vector<int> &dy){
        grid[row][col]  =2;
        for(int i =0;i<4;i++){
            int newrow = row + dx[i];
            int newcol = col + dy[i];
            
            if(newrow>=0 && newrow < n && newcol >=0 && newcol <m && grid[newrow][newcol] ==1){
                solve(newrow,newcol,n,m,grid,dx,dy);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        // boundry traversal on the grid if they are 1
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};
        
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                solve(0,j,n,m,grid,dx,dy);
            }
            if(grid[n-1][j]==1){
                solve(n-1,j,n,m,grid,dx,dy);
            }
        }
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                solve(i,0,n,m,grid,dx,dy);
            }
            if(grid[i][m-1]==1){
                solve(i,m-1,n,m,grid,dx,dy);
            }
        }
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1){
                    enclave(i,j,n,m,ans,grid,dx,dy);
                }
            }
        }
        return ans;
    }
    
    
};