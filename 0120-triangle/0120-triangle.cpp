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
        // whatever is the recursion here from 0 -> n-1 
        // the opposite will be tabulation
        
        int n = triangle.size();
        vector<int> prev(n,0);
        // space optimization
        // base case if i is n-1 j can be anything from 0 to n-1 in that row
        // anywhere we reach in last row is a base case
        for(int j =0;j<n;j++){
            prev[j] = triangle[n-1][j];
        }
        // so tabulation will be opposite n-1 to 0
        for(int i =n-2;i>=0;i--){
            vector<int> curr(n,0);
            // if i is 2 j can be 0 1 2
            for(int j =i;j>=0;j--){
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j+1];
                curr[j] = min(down, diagonal);
            }
            prev = curr;
        }
        return prev[0];
    }
};