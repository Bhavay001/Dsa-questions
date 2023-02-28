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

        // space optimization

        vector<int> prev(m,0);
        // base case
        
        for(int j=0; j<m; j++){
            prev[j] = matrix[0][j];
        }
    
        
        for(int i=1; i<n; i++){
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                
                int up = matrix[i][j] + prev[j];
                
                int diagright = 0;
                int diagleft = 0;
               
                if(j-1>=0){
                    diagleft = matrix[i][j] + prev[j-1];
                } 
                else{
                    diagleft += 1e9;
                }
                
                if(j+1<m){
                    diagright = matrix[i][j] + prev[j+1];
                } 
                else{
                    diagright += 1e9;
                }
                
                curr[j] = min({up,diagleft,diagright});
            }
            prev = curr;
        }
        
        int mini = prev[0];
        for(int j=1;j<m;j++){
            mini = min(mini,prev[j]);
        }
        
        return mini;
    }
};