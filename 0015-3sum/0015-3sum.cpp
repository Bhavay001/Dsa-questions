class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
 
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        
        // we will sort the nums then fix 1 pointer and solve problem as 2sum II where if sum is less 
        //we move to the right else we move to the left
        
        for(int i =0;i<nums.size()-2;i++){
            int low = i+1;
            int high = nums.size()-1;
            while(low<high){
                if(nums[i]+nums[low]+nums[high]==0){
                    st.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
                else if(nums[i]+nums[low]+nums[high]<0){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto x:st){
            ans.push_back(x);
        }
        
        return ans;
        
    }
};
