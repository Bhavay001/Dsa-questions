class Solution {
public:
    
    void solve(vector<int> &ans, vector<vector<int>> &finalans,vector<int> &visited, vector<int>&nums){
        // base case when ans vector becomes equal the size of the origional vector
        if(ans.size()==nums.size()){
            finalans.push_back(ans);
            return;
        }
        // we check the ans vector kif it is not visited we push it into our answer
        for(int i =0;i<nums.size();i++){
            if(!visited[i]){
                ans.push_back(nums[i]);
                visited[i] = 1;
                solve(ans,finalans, visited, nums);
                ans.pop_back();
                visited[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> finalans;
        vector<int> ans;
        vector<int> visited(n, 0);
        solve(ans, finalans , visited, nums);
        return finalans;
    }
};