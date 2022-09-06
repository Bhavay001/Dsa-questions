class Solution {
public:
    void permutations(int index , vector<int> &nums, vector<vector<int>> &ans){
        // base case is if index has become wequal to the size of the nums vector
        if(nums.size() == index){
            ans.push_back(nums);
            return;
        }
        // traverse from index to n-1
        for(int i =index;i<nums.size();i++){
            // once the swaps are done we make recursion call for the next states
            swap(nums[index] , nums[i]);
            permutations(index +1, nums, ans);
            // once we come back from recursion we re-swap it
            // backtracking
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(0, nums, ans);
        return ans;
    }
};