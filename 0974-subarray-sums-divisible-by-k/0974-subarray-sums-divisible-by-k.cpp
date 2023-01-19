class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0;
        int res = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        // we find repeating remainders as in betweek it the nubber would be divisible by k
        mp[0] = 1;
        for(int i =0;i<n;i++){
           // prefix sum           
            sum += nums[i]; 
            res = sum % k;
            // if modulus is negative we add res with k (+k -k concept) 
            if(res<0){
                res += k;
            }
            if(mp.find(res)!=mp.end()){
                // we add old frequency
                ans += mp[res];
                mp[res]++;
            }
            else{
                mp[res] = 1;
            }
              
        }
     
        return ans;
    }
};