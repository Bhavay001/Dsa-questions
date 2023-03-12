class Solution {
public:
    bool solve(int ind, int target, vector<int> & nums,vector<vector<int>> &dp){
        // base case if target = 0
        if(target == 0){
            return true;
        }
       // when index reaches 0 we check if the 0th index in array is equal to the target left return true
        if(ind == 0){
            return nums[0] == target;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        bool nottake = solve(ind -1,target,nums,dp);
        bool take = false;
        
        if(target>=nums[ind]){
            take = solve(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        //memoization
        int n = nums.size();
        int target = 0;
        for(int i =0;i<n;i++){
            target+=nums[i];
        }
        if(target%2!=0){
            return false;
        }
        target = target/2;
        // dp[size][target+1]
        // dp[ind+1][target+1]
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
    }
};

