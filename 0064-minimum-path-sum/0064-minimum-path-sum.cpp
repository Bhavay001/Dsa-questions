class Solution {
public:
    // memoization
    int solve(int m,int n, vector<vector<int>> & grid,vector<vector<int>> &dp){
        if(m==0 && n==0){
            return grid[m][n];
        }
        // Add a large value so that this path is not taken into consideration
        if(m<0 || n<0){
            return 1e9;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int left = grid[m][n] + solve(m-1,n,grid,dp);
        int right = grid[m][n] + solve(m,n-1,grid,dp);
        return dp[m][n] = min(left,right);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // tabulation bottom up
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }
                else if(i<0 || j<0){
                    return 1e9;
                }
                else{
                    int left = grid[i][j] + solve(i-1,j,grid,dp);
                    int right = grid[i][j] + solve(i,j-1,grid,dp);
                    dp[i][j] = min(left,right);
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};