class Solution {
public:
   //  this is the memoization code
    int solve(int m,int n,vector<vector<int>> &dp){
        if(m ==0 && n ==0){
            return 1;
        }
        if(m<0 || n<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int up = solve(m-1,n,dp);
        int left = solve(m,n-1,dp);
        return dp[m][n] = up + left;
        
    }
    int uniquePaths(int m, int n) {
        // space optmization
        vector<int> prev(n,0);
        
        for(int i = 0;i<m;i++){
            vector<int> temp(n,0);
            for(int j = 0;j<n;j++){
                if(i ==0 && j==0){
                    temp[j] = 1;
                }
                else{
                    int up=0;
                    int left=0;
                     if(i>0) up=prev[j];
                     if(j>0) left=temp[j-1];
                    temp[j]=left+up;
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};