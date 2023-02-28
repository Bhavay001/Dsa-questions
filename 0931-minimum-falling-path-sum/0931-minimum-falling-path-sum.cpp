class Solution {
public:
    // memoization
    int solve(int n, int m, vector<vector<int>> &matrix,vector<vector<int>> &dp){
        // column might go negative or column might exceed the last index
        if(m<0 || m>= matrix[0].size()){
            return 1e9;
        }
        // destination
        if(n==0){
            return matrix[n][m];
        }
        if(dp[m][n]!=-1){
            return dp[n][m];
        }
             
        int up = matrix[n][m] + solve(n-1,m,matrix,dp);
        int diagleft = matrix[n][m] + solve(n-1,m-1,matrix,dp);
        int diagright = matrix[n][m] + solve(n-1,m+1,matrix,dp);
        
        return dp[n][m] = min({up,diagleft,diagright});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(m,vector<int> (m,-1));
        int mini = INT_MAX;
        for(int i =0;i<m;i++){
            mini = min(mini,solve(n-1,i,matrix,dp));
        }
        return mini;
    }
};