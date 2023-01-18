class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // two conditions are possible the maximum sum is not in circulaar but normal
        // other is maximum sum is formed by circular sum
        //to solve the first we can simply apply kadanes algo
        // to solve the circular sum we need to find the minimum subarray and
        // subract it from total sum
       
        int minsum = 0;
        int maxsum = 0;
        int totalsum = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i =0;i<nums.size();i++){
            totalsum += nums[i];
            minsum +=nums[i];
            maxsum += nums[i];
            
            maxi= max(maxsum , maxi);
            if(maxsum<0){
                maxsum = 0;
            }
            
            mini = min(minsum , mini);
            if(minsum>0){
                minsum = 0;
            }
        }
        
        return totalsum==mini?maxi:max(maxi,totalsum-mini);
    }
};