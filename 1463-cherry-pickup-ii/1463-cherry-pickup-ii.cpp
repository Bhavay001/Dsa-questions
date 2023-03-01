class Solution {
public:
    // we have not taken i1 and i2 as we will move down together (both robots move together)
    int solve(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        //base cases
        // handling out of bound cases either they can exceed m or go lesss than 0
        if (j1<0 || j1>=m || j2<0 || j2>=m){
                return -1e9;
        }
            // reached last row
        if (i == n-1) {
            if (j1 == j2){
                return grid[i][j1];
            }
            else{
                //robot1 + robot2
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }
        // if robot 1 moves left robot 2 has 3 options so in total there are 3 x 3 9 paths
        int maxi = INT_MIN;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int ans;
                if (j1 == j2)
                    ans = grid[i][j1] + solve(i+1, j1+d1, j2+d2, n, m, grid,dp);
                else
                    ans = grid[i][j1] + grid[i][j2] + solve(i+1, j1+d1, j2+d2, n, m, grid,dp);
                maxi = max(maxi, ans);
            }
        }
        return dp[i][j1][j2] = maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
      
        int n = grid.size();
        int m = grid[0].size();
        
        // int dp[n][m][m]
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,n,m,grid,dp);
    }
};

