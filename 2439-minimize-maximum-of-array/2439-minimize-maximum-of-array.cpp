class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
      
        // now the minimum we can make will be the AVERAGE 
        // ill first make a prefix sum array
        
        vector<double> prefix(n);
        prefix[0] = nums[0];
        for(int i =1;i<nums.size();i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
         // we can shift the values to the left but we cannot shift the values to the right 
        // so the minimum maximum cannot be less than the first element as its value can never be decreamented
        
        int res  = nums[0];
        for(int i = 1;i<n;i++){
            double num = prefix[i];
            double den = i + 1;
            int avg = ceil(num/den);
            res = max(res,avg);
        }
        
        return res;
    }
};
