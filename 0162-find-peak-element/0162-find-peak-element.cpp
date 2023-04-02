class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size()-1;
        if(nums.size()==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n]>nums[n-1]){
            return n;
        }
        int s = 1;
        int e = nums.size()-2;
        
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid] ){
                return mid;
            }
            else if(nums[mid]<nums[mid+1]){
                s = mid+1;
            }
            else{
               e = mid-1;
            }
        }
        return -1;
    }
};
