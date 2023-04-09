class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        // we will maintain a range of left to right with will initially be at index 0
        int left = 0;
        int right = 0;
        
        
        while(right<nums.size()-1){
            int farthest = 0;
            // we will traverse the range and find the farthest point
            for(int i = left;i<=right;i++){
                farthest = max(farthest,i+ nums[i]);
            }
            ans++;
            left = right +1;
            right = farthest;
        }
        return ans;
    }
};