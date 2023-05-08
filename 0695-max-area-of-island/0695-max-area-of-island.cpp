class Solution {
public:
    
    void dfs(vector<vector<int>> &grid,int row,int col ,int n,int m,vector<int> &dx, vector<int>&dy,int &ans){
        grid[row][col] = 0;
        ans++;
        
        for(int i =0;i<4;i++){
            int newrow = dx[i] + row;
            int newcol = dy[i] + col;
            
            if(newrow>=0 && newrow<n && newcol>=0 && newcol <m && grid[newrow][newcol] ==1){
                dfs(grid,newrow,newcol,n,m,dx,dy,ans);
            }
                
        }
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
 
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        

        int maxans = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    int ans = 0;
                    dfs(grid,i,j,n,m,dx,dy,ans);
                    maxans = max(ans,maxans);
                }
            }
        }
        
        return maxans;
        
    }
}; 