class Solution {
public:
    int solve(int row,int col,vector<vector<int>> &grid,int n,int m,vector<vector<int>> &dp){
 
        if(row>n || row<0 || col>m || col<0){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        
        int diagup = 0;
        if(row-1>=0 && col+1<=m && grid[row-1][col+1]>grid[row][col]){
            diagup = 1+ solve(row - 1, col + 1,grid,n,m,dp);
        }
        
        int right = 0;
        if(col+1<=m && grid[row][col+1]>grid[row][col]){
            right = 1+ solve(row, col + 1,grid,n,m,dp);
        }
        
        int diagdown =0;
        if(row+1<=n && col+1<=m && grid[row+1][col+1]>grid[row][col]){
            diagdown = 1 + solve(row + 1, col + 1,grid,n,m,dp);
        }
        return dp[row][col] = max({diagup,right,diagdown});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int i =0;i<n;i++){
            ans = max(ans,solve(i,0,grid,n-1,m-1,dp));
        }
        return ans;
    }
};