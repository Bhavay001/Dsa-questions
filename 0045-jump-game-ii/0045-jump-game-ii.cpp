class Solution {
public:
    
    // memoization solution
    int solve(int ind,int n, vector<int>&nums,vector<int> &dp){
        // if we have reached the end we do not have to move further
        if(ind == n-1){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int mini = 1e9;
        for(int j =1;j<=min(n-ind-1,nums[ind]);j++){
            int step = 1 + solve(ind + j,n,nums,dp);
            mini = min(mini,step);
        }
        return dp[ind] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};