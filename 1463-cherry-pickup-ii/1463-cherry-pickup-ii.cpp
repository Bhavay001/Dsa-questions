class Solution {
public:
    // memoization
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
        
        // space optimization
        // base case
        
        vector<vector<int>> front(m,vector<int>(m,0));
        vector<vector<int>> curr(m,vector<int>(m,0));
        
        for(int j1 = 0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if (j1 == j2){
                    front[j1][j2] =  grid[n-1][j1];
                }
                else{
                    front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }
        // recursion was from 0 ->n-1 so the tabulation will be from n-1 to 0
        // represent in the form of loops
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    // if robot 1 moves left robot 2 has 3 options so in total there are 3 x 3 9 paths
                    int maxi = INT_MIN;

                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int ans;

                            if (j1 == j2){
                                ans = grid[i][j1];
                            }
                            else{
                                ans = grid[i][j1] + grid[i][j2];
                            }

                            if(j1+d1 <0 || j1+ d1 >=m || j2+ d2<0 || j2 + d2>=m){
                                ans += -1e9;
                            }
                            else{
                                ans += front[j1+d1][j2+d2];
                            }
                            maxi = max(maxi, ans);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][m-1];
    }
};

