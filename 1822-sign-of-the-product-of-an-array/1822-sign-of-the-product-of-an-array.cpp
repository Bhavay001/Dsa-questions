class Solution {
public:
    int arraySign(vector<int>& nums) {
        double product = 1;
        for(int i =0;i<nums.size();i++){
            product = nums[i] * product;
        }
        // cout<<product;
        if(product==0){
            return 0;
        }
        else if(product > 0){
            return 1;
        }
        else if(product<0){
            return -1;
        }
        return 0;
    }
};