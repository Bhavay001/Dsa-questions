class Solution {
public:
    int solve(int ind,vector<int>&nums,vector<int> &dp){
        if(ind==0){
            return nums[0];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int notpick = solve(ind-1,nums,dp);
        int pick = nums[ind] + solve(ind-2,nums,dp);
        return dp[ind] = max(notpick,pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return max(solve(n-1,nums,dp),solve(n-2,nums,dp));
    }
};