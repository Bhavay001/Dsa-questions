class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans;
    
        int s = 0;
        int e = nums.size()-1;
        int res = -1;
        
        int mid = s + (e-s)/2;
        
        while(s<=e){
            if(nums[mid] == target){
                res = mid;
                e = mid-1;
            }
            else if(nums[mid]>target){
                e = mid -1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        
        ans.push_back(res);
        
        res = -1;
        s = 0;
        e = nums.size()-1;
        
        mid = s + (e-s)/2;
        
        while(s<=e){
            if(nums[mid] == target){
                res = mid;
                s = mid+1;
            }
            else if(nums[mid]>target){
                e = mid -1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        ans.push_back(res);
        return ans;
        
    }
};