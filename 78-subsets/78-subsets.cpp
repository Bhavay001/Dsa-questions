class Solution {
public:
    
    void solve(int index ,vector<int>&ans, vector<vector<int>> &finalans , vector<int> nums){
        
        if(index>=nums.size()){
            finalans.push_back(ans);
            return;
        }
        
        // take or pick the particular index into the subsequence
        ans.push_back(nums[index]);
        solve(index+1,ans,finalans,nums);
        
        // not pick , not take condition, this element is not added in the subsequence
        ans.pop_back();
        solve(index+1,ans,finalans,nums);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> finalans;
        vector<int> ans;
        int index = 0;
        solve(index, ans, finalans ,nums);
        return finalans;
    }
};