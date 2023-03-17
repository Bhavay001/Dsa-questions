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
        
         if(totalsum -target < 0 || (totalsum -target) % 2 !=0 ){
            return 0;
        }
        
        int sum = (totalsum -target)/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        
        return solve(n-1,sum,arr,dp);
    }
};