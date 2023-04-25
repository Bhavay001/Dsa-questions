class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int currlen = 1;
        int maxlen = 1;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i]== nums[i+1]){
                continue;
            }
            if(nums[i+1] == nums[i]+1){
                currlen++;
                maxlen= max(maxlen,currlen);
            }
            else{
                currlen = 1;
            }
        }
        return maxlen;
    }
};