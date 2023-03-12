class Solution {
public:

    bool canPartition(vector<int>& nums) {
        //space optimization
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
        vector<bool> prev(sum+1,0);
        vector<bool> curr(sum+1,0);
        
        // if target == 0
        prev[0] = curr[0] = true;
    
        // if index = 0
        if(nums[0]  <= sum){
            prev[nums[0]] = true;
        }
        
        for(int ind = 1;ind<n;ind++){
            for(int target = 1;target<=sum;target++){

                bool nottake = prev[target];
                bool take = false;

                if(target>=nums[ind]){
                    take = prev[target-nums[ind]];
                }
                
                curr[target] = take || nottake; 
            }
            prev = curr;
        }
        return prev[sum];
    }
};

