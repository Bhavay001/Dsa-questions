class Solution {
public:
    
    int solve(vector<int>& arr){
        int n = arr.size();
        if(n==1){
            return arr[0];
        }
        int prev2 = arr[0];
        int prev =  max(arr[0],arr[1]);
        
        for(int i =2;i<n;i++){
            int pick = prev2 + arr[i];
            int notpick = prev;
            int curr = max(pick,notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
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