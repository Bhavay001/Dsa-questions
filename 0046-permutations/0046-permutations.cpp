class Solution {
public:
    
    void solve(int index , int count, vector<int> &nums,vector<vector<int>> &finalans, vector<int> &ans, vector<int> &visited,int n){
        
        if(count == n){
            finalans.push_back(ans);
            return;
        }
        
        for(int i =0;i<n;i++){
            if(visited[i]==0){
                ans.push_back(nums[i]);
                count += 1;
                visited[i] = 1;
                solve(index+1,count, nums,finalans, ans, visited , n);
                ans.pop_back();
                count -=1;
                visited[i]= 0;
            }
        }
    
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> finalans;
        vector<int> ans;
        int index = 0;
        int count = 0;
        int n = nums.size();
        vector<int> visited(n,0);
        solve(index ,count ,nums,finalans, ans, visited ,n);
        return finalans;
    }
};