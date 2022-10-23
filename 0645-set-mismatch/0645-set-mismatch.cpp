class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==2){
                ans.push_back(nums[i]);
            }
        }
        int count = 1;
        for(auto x:mp){
            if(x.first!=count){
                ans.push_back(count);
                break;
            }
            count++;
        }
        if(ans.size()==1){
            ans.push_back(count);
        }
        return ans;
    }
};