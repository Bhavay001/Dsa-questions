class Solution {
public:
    
    void solve(int index, vector<int> &nums, vector<int>& ans, vector<vector<int>>& finalans){
        
         finalans.push_back(ans);
        for(int i = index ;i<nums.size();i++){
            if(i>index && nums[i] == nums[i-1]){
                continue;
            }
            ans.push_back(nums[i]);
           
            solve(i+1,nums,ans,finalans);
            ans.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalans;
        int index = 0;
        sort(nums.begin(),nums.end());
        solve(index, nums, ans, finalans);
        // vector<int> empty;
        // finalans.push_back(empty);
        return finalans;
    }
};