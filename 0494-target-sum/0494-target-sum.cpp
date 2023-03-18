class Solution {
public:
    
    int solve(int ind,int target,vector<int> & arr,vector<vector<int>> &dp){
        
        if(ind == 0){
            if(target == 0 && arr[0]==0){
                return 2;
            }
            //arr[0] might might be some number not 0 so we do not pick
            //arr[0] migthbe equal to target we pick
            if(target == 0 || arr[0]==target){
                return 1;
            }
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int notpick = solve(ind-1,target,arr,dp);
        int pick = 0;
        
        if(arr[ind]<=target){
            pick = solve(ind-1,target-arr[ind],arr,dp);
        }
        
        return dp[ind][target] = (pick + notpick);
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        
        // same as subesets with given difference s1-s2 = d
        // s1 be sum of possitve numbers and s2 be sum of negative numbers
        int n = arr.size();
        int totalsum =0;
        for(int i =0;i<n;i++){
            totalsum += arr[i];
        }
        
        // base case s2 cannot be negative as subset sum will be possitive of possitive elements
        // s2 cannot be odd as all digits are whole numbers 
        if(totalsum -target < 0 || (totalsum -target) % 2 !=0 ){
            return 0;
        }
        
        int sum = (totalsum - target)/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        
        // base case
        if(arr[0]==0){
            dp[0][0] = 2;
        }
        else{
            dp[0][0] = 1;
        }
        
        if(arr[0] != 0 && arr[0]<=sum){
            dp[0][arr[0]] = 1;
        }
        
        for(int ind = 1;ind<n;ind++){
            for(int target = 0;target<=sum;target++){
                
                int notpick = dp[ind-1][target];
                int pick = 0;
                
                if(arr[ind]<=target){
                    pick = dp[ind-1][target-arr[ind]];
                }
                
                dp[ind][target] = (pick + notpick);
            }
        }
        
        return dp[n-1][sum];
    }
};