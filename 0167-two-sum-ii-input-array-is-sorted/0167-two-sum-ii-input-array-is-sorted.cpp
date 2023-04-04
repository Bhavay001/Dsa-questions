class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        vector<int> ans;
        while(i<=j){
            if(nums[i]+nums[j]==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if(nums[i]+ nums[j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};