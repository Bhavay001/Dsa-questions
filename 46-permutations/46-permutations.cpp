class Solution {
public:
    
    void permutations(vector<int> &nums, vector<vector<int>>& ans, int freq[] ,vector<int> &ds){
        // base case 
        // agar ds vector ka size nums kai size kai equal ho gya to ek permutation ton mil gyi push karke return
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
    
        for(int i =0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                permutations(nums,ans,freq,ds);
                ds.pop_back();
                freq[i] = 0;
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i =0;i<nums.size();i++){
            freq[i] = 0;
        }
        permutations(nums, ans, freq, ds);
        return ans;
    }
};