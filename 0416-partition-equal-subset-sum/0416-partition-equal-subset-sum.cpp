class Solution {
public:

    bool canPartition(vector<int>& nums) {
        //tabulation bottom up
        int n = nums.size();
        int sum = 0;
        for(int i =0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        sum = sum/2;
        // dp[size][target+1]
        // dp[ind+1][target+1]
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        
        // if target == 0
        for(int i =0;i<n;i++){
            dp[i][0] = true;
        }
        // if index = 0
        if(nums[0]  <= sum){
            dp[0][nums[0]] = true;
        }
        
        for(int ind = 1;ind<n;ind++){
            for(int target = 1;target<=sum;target++){

                bool nottake = dp[ind -1][target];
                bool take = false;

                if(target>=nums[ind]){
                    take = dp[ind-1][target-nums[ind]];
                }
                
                dp[ind][target] = take || nottake; 
            }
        }
        return dp[n-1][sum];
    }
};

