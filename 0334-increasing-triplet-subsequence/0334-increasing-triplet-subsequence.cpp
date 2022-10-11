class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // we will maintain a left min array and a right max array and check if the curr eleement lies in the 
        // middle of it
        vector<int> left;
        vector<int> right;
        int leftmin = INT_MAX;
        int rightmax = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(leftmin>nums[i]){
                leftmin = nums[i];
            }
            left.push_back(leftmin);
        }

        for(int i=nums.size()-1; i>=0 ;i--){
            if(rightmax<nums[i]){
                rightmax = nums[i];
            }
            right.push_back(rightmax);
        }
        reverse(right.begin(),right.end());

        for(int i=0;i<nums.size();i++){
            if(left[i]<nums[i] && nums[i]<right[i]){
                return true;
            }
        }
        return false;
    }
};