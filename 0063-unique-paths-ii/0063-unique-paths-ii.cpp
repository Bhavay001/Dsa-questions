class Solution {
public:
    int solve(int m ,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>> & dp){
        // if we reach the start point and tha start point is not obstacle we return 1
        if(m==0 && n==0 && obstacleGrid[m][n]!=1){
            return 1;
        }
        // we do not take the way if the way has obstacle
        if(m<0 || n<0 || obstacleGrid[m][n]==1){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int left = solve(m-1,n,obstacleGrid,dp);
        int up = solve(m,n-1,obstacleGrid,dp);
        
        return dp[m][n] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        //memoization 
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,obstacleGrid,dp);
    }
};