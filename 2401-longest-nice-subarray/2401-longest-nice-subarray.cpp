class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // sliding window
        int ans = 0;
        int i =0;
        int j =0;
        int num = 0;
        while(j<nums.size()){
            while((num & nums[j]) !=0){
                // if num & nums[j] != 0 then i will have to slide the window forward
                // by moving the i pointer forward i will have to unset the bit it made set
                // we can do this by xoring by itself and moving i forward
                num = num ^ nums[i++];
            }
            
            // if & is equal we move forward store the size and make the bits set
            num = num | nums[j]; // making bits set 
            ans = max(ans, j-i+1); // maximum b/w window or previous window andwer stored
            j++; // move forward
        }
        return ans;
    }
    
};