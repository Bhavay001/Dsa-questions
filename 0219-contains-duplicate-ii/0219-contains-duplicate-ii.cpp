class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i =0;i<nums.size();i++){
            
            // not present
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]] = i;
            }
            
            // present
            else{
                // present hai to check karna hai ki current index - jo pehle aaya to wo chota hai ya k se
                if(abs(i-mp[nums[i]])<=k){
                    return true;
                }
                // warna map mai stores index ko abhi waale se change kardiya
                else{
                    mp[nums[i]] = i;
                }
            }
            
        }
        return false;
    }
};