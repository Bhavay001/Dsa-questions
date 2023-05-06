class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1e9 + 7;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int ans = 0;
        int n = nums.size();
        vector<int>pow2(n+1,1);
        for(int i=1;i<=n;i++)
        {
            pow2[i]=(2*pow2[i-1])%MOD;
        }
        
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                int size = j-i;
                int add = 1;
                ans = (ans + pow2[size]) % MOD;
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};