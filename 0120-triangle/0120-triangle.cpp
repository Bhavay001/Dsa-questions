class Solution {
public:
    int solve(int n,int m,vector<vector<int>>& triangle,vector<vector<int>> &dp){
    
        // whichever column we reach we return that
        if(n==triangle.size()-1){
            return triangle[n][m];
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        // we can either go down or digonal on the right side
        int down = triangle[n][m] + solve(n+1,m,triangle,dp);
        int diagonal = triangle[n][m] + solve(n+1,m+1,triangle,dp);
        return dp[n][m] = min(down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        // memoization
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,triangle,dp);
    }
};