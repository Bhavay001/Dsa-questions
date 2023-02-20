class Solution {
public:
// this is the tabulation bottom-up approach of house roober just that it was given in a circle
// so i first gave an array find maxsum where 1st element was not included
//then found for array where last element is not present as both cannot be together in same ans
// returned maximum among both the arrays 
    int solve(vector<int>& arr){
        int n = arr.size();
        vector<int> dp(n,-1);
        dp[0] = arr[0];
        dp[1] =  max(arr[0],arr[1]);
        
        for(int i =2;i<n;i++){
            int pick = dp[i-2] + arr[i];
            int notpick = dp[i-1];
             dp[i] = max(pick,notpick);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }

        vector<int> dp(n,-1);
        vector<int> arr1;
        vector<int> arr2;
        for(int i =0;i<n;i++){
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }

        return max(solve(arr1),solve(arr2));
    }
    

};